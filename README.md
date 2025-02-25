# 42minitalk
Projet du 3ème cercle du cursus 42

# Notions importantes
## signal() // sigaction()

## SIGUSR1 et SIGUSR2
Ce sont des signaux de base dont les effets exacts sont déterminés par l'utilisateur-ice ou plutôt lae développeur-euse. Dans ce projet, j'ai choisi d'envoyer SIGUSR1 quand je veux signaler que le bit traité est un 0, et SIGUSR2 pour les 1. Ainsi, à l'endroit du code qui doit envoyer un 0, j'utilise SIGUSR1, et à l'endroit du code qui doit traiter le signal, je dis que si on a reçu un SIGUSR1, il faut comprendre et donc traiter le bit actuel comme un 0. Et inversément pour les 1.

## kill()
Le choix du nom de la méthode kill() vient de son histoire. A l'origine, elle servait uniquement à "tuer" des process. Petit à petit, l'utilisation s'est agrandie, mais le terme est resté. Dans ce projet, on l'utilise pour interrompre le process du serveur afin qu'il sorte de sa boucle infinie le temps de gérer le signal reçu.

## getpid()
Le PID (= identificateur de process) sert à... identifier le process. Cela permet notamment de faire agir kill() sur le bon process. Comme son nom l'indique, la fonction getpid() permet d'obtenir le PID du process où elle est appelée.

## exit()
La méthode exit() permet de quitter le programme "normalement". Si vous devez faire cesser votre programme dans une situation définie qui n'est pas simplement "arriver à la dernière ligne", utilisez exit(). Dans ce projet, on l'utilise lorsqu'une erreur est détectée.

## Bit shifting
Pour être sûr-e de pouvoir transmettre n'importe quel caractère avec une seule et même méthode, le plus simple est encore de s'en remettre au binaire. Dans ce projet, on transmet donc les caractères bit par bit, en prenant soin de commencer par le dernier bit du premier char. A la réception, on n'oublie donc pas, à chaque nouveau bit reçu, de décaler de 1 les bits du char actuellement traité: ``current_char <<= 1``. Je n'ai pas encore compris pourquoi on ne pourrait pas juste les passer dans le bon ordre dès le début: je suppose que c'est du au fonctionnement du binaire en lui-même.

# Stratégie
## Fonctionnement global
- Le "client" et le "serveur" sont en réalité juste deux programmes (= deux fichiers .c avec chacun leur main).
- Le client est exécuté avec le PID du serveur et un message en arguments, il "encrypte" le message puis utilise le PID du serveur et SIGURS1 pour envoyer "0" ou SIGURS2 pour envoyer "1" au serveur (je crois).
- Le serveur imprime son PID puis tourne à l'infini, afin d'être constamment prêt à recevoir les signaux du clients. Il "décrypte" le message envoyé par le client et l'imprime.
- Les deux programmes doivent donc tourner en même temps: on appelle ça des process. 
- Le Makefile doit créer deux exécutables, un par process/programme/fichier.c avec main. Lancer d'abord le serveur puis le client.
Droit à une globale par process si elle a du sens, et à autant de var static que je veux.
Apparemment faut initialiser des trucs (?) mais pas besoin de déclarer la structure sigaction (?) qui est en fait aussi une fonction (?) et puis pour l'encryptage il faut shift des bits parce que??

## server.c (pseudo-code)

### main()
```
int  main(void)
{
  getpid()
  printf("%s", pid)
  signal(SIGUSR1, handle_signal)
  signal(SIGUSR2, handle_signal)
  while (1)
    usleep(100)
}
```
### handle_signal()
```
handle_signal()
{
  static unsigned char	current_char;  	//à chaque appel de handle signal, donc à chaque signal reçu, donc à chaque bit reçu, on reprend la dernière valeur de current_char
  static int 		i; 		//idem pour int

  current_char |= (signal == SIGUSR2) 	// |= veut dire assigne le résultat de la comparaison (signal == SIGUSR2) à current_char.
  i ++;
  if i == 8				// un byte est composé de 8 bits
    if current_char == END_OF_MESSAGE 	// '\0'
      write(1, "\n", 1);			
    else
      write(1, &current_char, 1);	// on imprime directement car stocker reviendrait à surcharger la mémoire d'allocations réallocations libérations (notamment si message trop long) + l'utilisateur attendrait trop longtemps avant de voir le message apparaître
    i = 0;				// vu qu'on passe au byte suivant, on réinitialise l'index
    current_char = 0; 			// idem
  else
	current_char <<= 1; 		// current_char = current_char << 1 : on décale les bit de 1
}
```


## client.c (pseudo-code)
### main()
```
int  main(int argc, char **argv)
{
  struct sigaction	sig_hook;

  gestion erreurs: pas de PID ou pas de message, PID ou message invalide,...; Si erreur, exit(0) 	//pid = argv[1], message = argv[2]
  while (ft_strlen(message)) 										//on utilise ft_strlen pour éviter de devoir incrémenter un index ici
    encrypt_and_send_bit_by_bit(message)
}
```

### encrypt_and_send_bit_by_bit(char *message)
```
void encrypt_and_send_bit_by_bit(char *message)
{
  unsigned char temp;
  int		i;

  i = 0
  while (message[i])
    j = 8
    temp = message[j]
    while (j)
        temp = message[i] >> j
        if temp % 2 == 0    	// --> if (char[j] == 1 || 0), en fonction du bit 
          kill(pid, SIGUSR1) 	// envoie 0
        else
          kill(pid, SIGUSR2) 	// envoie 1
        usleep(42)
      j --;
    i ++;
}
```
