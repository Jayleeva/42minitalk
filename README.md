Projet du 3ème cercle du cursus 42

# Stratégie
## Fonctionnement global
- Le "client" et le "serveur" sont en réalité juste deux programmes (= deux fichiers .c avec chacun leur main).
- Utilisation: lancer d'abord le serveur puis le client.
- Le client est exécuté avec le PID du serveur et un message en arguments, il utilise le PID du serveur et SIGURS1 ou SIGURS2 pour envoyer "0" ou "1" au serveur, bit par bit, byte par byte, char par char, jusqu'à avoir envoyé tout le message par **bit shifting**.
- Le serveur imprime son PID puis tourne à l'infini, afin d'être constamment prêt à recevoir les signaux du clients. Il reçoit chaque bit du message envoyé par le client, confirme la réception grâce à une variable globale, et imprime les chars reconstitués par **bit shifting**.
- Les deux programmes doivent donc tourner en même temps: on appelle ça du **multi-process**. 
- Le Makefile doit créer deux exécutables, un par process/programme/fichier.c avec main.

# Notions importantes
## signal() // sigaction()
### signal()
La syntaxe de signal() est un peu déroutante: elle prend en premier argument le signal reçu (dans ce projet, soit SIGUSR1 soit SIGUSR2), et en deuxième argument la fonction à lancer quand un signal est reçu, qui elle-même prend le signal reçu en argument, de manière sous-entendue. En gros, elle vérifie si on a bien reçu un signal SIGUSR1 ou SIGUSR2, et si oui, elle lance la fonction handle_signal() avec en argument SIGUSR1/2.

### sigaction()
Sigaction de son cote est encore plus déroutante. Il faut la déclarer en type structure ``struct sigaction your_struct_name``, puis déclarer ses propriétés, par ex:
```
your_struct_name.sa_flags = your_flag1 | your_flag2;
your_struct_name.sa_mask = your_set_name
your_struct_name.sa_sigaction = &your_function
```

Ensuite, pour que le programme puisse recevoir le signal, on l'appelle ainsi: ``sigaction(your_signal, &your_struct_name, NULL);``.

Si vous souhaitez utiliser un mask, il faut déclarer un set: ``sigset_t your_set_name`` et l'assigner: ``sigemptyset(&your_set_name); sigaddset(&your_set_name, your_signal);``.

Le sigemptyset permet de s'assurer que le set est vide, et le sigaddset permet d'y ajouter les signaux que l'on desire.


Que choisir entre sigaction et signal? Si signal() est plus facile a comprendre, elle est aussi moins forte: elle peut etre parasitee par d'autres signaux, ne permet pas de passer des infos supplementaires comme le PID de l'envoyeur, est globalement moins "malleable".  

## SIGUSR1 et SIGUSR2
Ce sont des signaux de base déterminés par l'utilisateur-ice ou plutôt lae développeur-euse. Dans ce projet par exemple, j'ai choisi d'envoyer SIGUSR1 quand je veux signaler que le bit traité est un 0, et SIGUSR2 pour les 1. Ainsi, à l'endroit du code qui doit envoyer un 0, j'envoie SIGUSR1, et à l'endroit du code qui doit traiter le signal, je dis que si on a reçu un SIGUSR1, il faut comprendre et donc traiter le bit actuel comme un 0. Et inversément pour les 1. 

A retenir: SIGUSR1 et SIGUSR2 n'envoient rien en soi. C'est à vous de définir, au moment d'envoyer l'un où l'autre, sous quelles conditions les envoyer *eux*. Ils ne transportent aucune information, aucune valeur, aucune donnée. C'est à vous de savoir que vous envoyez SIGUSR1 dans la situation x et SIGUSR2 dans la situation y, et donc de traiter cette info en conséquence. 

## kill()
Le choix du nom de la méthode kill() vient de son histoire. A l'origine, elle servait uniquement à "tuer" des process. Petit à petit, l'utilisation s'est agrandie, mais le terme est resté. Dans ce projet, on l'utilise pour interrompre le process du serveur afin qu'il sorte de sa boucle infinie le temps de gérer le signal reçu.

## getpid()
Le PID (= identificateur de process) sert à... identifier le process. Cela permet notamment de faire agir kill() sur le bon process. Comme son nom l'indique, la fonction getpid() permet d'obtenir le PID du process où elle est appelée.

## exit()
La méthode exit() permet de quitter le programme "normalement". Si vous devez faire cesser votre programme dans une situation définie qui n'est pas simplement "arriver à la dernière ligne", utilisez exit(). Dans ce projet, on l'utilise lorsqu'une erreur est détectée.

## sleep() | usleep() | pause()
Toutes ces methodes servent à mettre un processus en pause pendant un temps défini. Par defaut, pause() agit pendant 100 microsecondes, ce qui revient au même qu'écrire ``usleep(100)``. La différence entre sleep() et usleep() repose dans l'unité utilisée: sleep() agit en secondes, et ulseep() en microsecondes.

## Bit shifting
Pour être sûr-e de pouvoir transmettre n'importe quel caractère avec une seule et même méthode, et en n'ayant droit qu'à deux signaux, le plus simple est encore de s'en remettre au binaire. Dans ce projet, on transmet donc les caractères bit par bit: 

**Dans le client**
- on "shift" tout d'abord notre char de 7 bits vers la droite dans une temporaire (afin de "pousser" le premier bit du premier char en dernier bit de la temporaire, sans modifier le char original). Ainsi, si le premier bit du premier char est égal à 1, la temporaire devient 00000001. S'il est égal à 0, la temporaire devient 00000000.
- ensuite, on vérifie le modulo 2 de la temporaire (par ex.: 00000000 % 2), ce qui revient au final à vérifier le modulo 2 du dernier bit (puisque 00000000 est egal a 0 et 00000001 est egal a 1). Si ce modulo est égal à 0, cela veut dire que le dernier bit est un 0, et qu'on doit donc lancer le signal qui indique un 0 (chez moi, SIGUSR1). L'inverse s'il est égal à 1. 
- on lance le signal correspondant à la valeur du bit déterminée ci-dessus.
- on recommence en shiftant cette fois de 6 vers la droite; à la prochaine itération, ce sera de 5, puis de 4, etc. Ainsi, on parcourt et envoie l'entierté du byte, un bit à la fois.

**Dans le serveur**
- une statique de type unsigned char va "reconstruire" le byte envoyé bit par bit. D'abord initialisée à 0 (soit 00000000 en binaire), on lui applique ensuite (sur 8 itérations, puisqu'un byte est constitué de 8 bits) un OU logique ``unsigned_char |= (signal_recieved == SIGUSR_signaling_1)``: plusieurs choses se passent ici.
- tout d'abord, on vérifie si le signal reçu est bien celui qui indique un 1: si c'est le cas, on combinera donc notre unsigned char avec ``true``, soit 1, soit 00000001 en binaire, sinon, on le combinera avec ``false``, soit 0, soit 00000000 en binaire. --> ``unsigned_char |= bit_recieved``. 
- puis notre unsigned char est réassigné: il prend comme valeur le résultat de: lui-même combiné au bit reçu --> ``unsigned_char = unsigned_char | bit_recieved``. Le ``|`` signifie la combinaison des deux variables, avec une logique de "OU": on "surperpose" les deux en binaire, et on regarde les bits de chacune par colonne: si au moins un est un 1, alors ce sera un 1, si aucun n'est un 1, ce sera un 0. Si on avait utilisé un ET logique, il aurait fallu que les deux soit des 1 pour que le résultat final garde un 1.

Voici un exemple où l'unsigned char, d'abord assigné à 0, reçoit premièrement un 0, puis un 1, puis un 0, et ainsi de suite. A la fin des 8 itérations, il aura pris la valeur du char 'U': 01010101. 
```
   00000000 char assigné à 0
   00000000 char réassigné à lui-même + 0, donc pas de changement
0  00000000 <- dernier bit poussé (shifted) pour pouvoir accueillir le bit suivant; un nouveau zéro vient en "placeholder"; le premier bit en partant de la gauche est "sorti" du byte
   00000001 char réassigné à lui-même + 1
0  00000010 <- dernier bit poussé ...
   00000010 char réassigné à lui-même + 0, donc pas de changement
0  00000100 <- dernier bit poussé ...
   00000101 char réassigné à lui-même + 1
0  00001010 <- etc.
   00001010
0  00010100 <-
   00010101
0  00101010 <-
   00101010
0  01010100 <-
   01010101
```
