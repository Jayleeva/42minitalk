# 42minitalk
Projet du 3ème cercle du cursus 42

# Stratégie
## Fonctionnement global
- Le "client" et le "serveur" sont en réalité juste deux programmes (= deux fichiers .c avec chacun leur main).
- Le client est exécuté avec le PID du serveur et un message en arguments, il encrypte le message puis utilise le PID du serveur et SIGURS1 pour envoyer "0" ou SIGURS2 pour envoyer "1" au serveur (je crois).
- Le serveur imprime son PID puis tourne à l'infini, afin d'être constamment prêt à recevoir les signaux du clients. Il décrypte le message envoyé par le client et l'imprime.
- Les deux programmes doivent donc tourner en même temps: on appelle ça des process. 
- Le Makefile doit créer deux exécutables, un par process/programme/fichier.c avec main. Lancer d'abord le serveur puis le client.
Apparemment faut initialiser des trucs (?) mais pas besoin de déclarer la structure sigaction (?) qui est en fait aussi une fonction (?) et puis pour l'encryptage il faut shift des bits parce que??
Droit à une globale par process si elle a du sens (?), et apparemment à autant de var static que je veux (?)

## server.c (pseudo-code)
### main()
```
int  main(void)
{
  getpid()
  printf(pid)
  signal(SIGURS1, )
  signal(SIGURS2, )
  while (1)
    usleep(100)
}
```

### ()
```

{

}
```

### stock(bit_d)
```

{
  t_node->next = malloc(sizeof(t_node))
  t_node->next = bit_d
  t_node->next->next = NULL
}
```

## client.c (pseudo-code)
### main()
```
int  main(int argc, char **argv)
{
  struct sigaction	sig_hook;

  gestion erreurs: pas de PID ou pas de message, PID ou message invalide,...;
  while (ft_strlen(message))
    encrypt_and_send_bit_by_bit(message)
}
```

### encrypt_and_send_bit_by_bit(char *message)
```

```
