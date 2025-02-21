# 42minitalk
Projet du 3ème cercle du cursus 42

# Stratégie
## Fonctionnement global
- Le "client" et le "serveur" sont en réalité juste deux programmes (= deux fichiers .c avec chacun leur main).
- Le client est exécuté avec le PID du serveur et un message en arguments, il encrypte le message puis utilise le PID du serveur et SIGURS1 pour envoyer "0" ou SIGURS2 pour envoyer "1" au serveur .
- Le serveur imprime son PID puis tourne à l'infini, afin d'être constamment prêt à recevoir les signaux du clients. Il décrypte le message envoyé par le client et l'imprime.
- Les deux programmes doivent donc tourner en même temps: on appelle ça des process. 
- Le Makefile doit créer deux exécutables, un par process/programme/fichier.c avec main. On les lance en même temps? avec ./client PID message ./server ? D'abord ./server [press enter] puis ./client PID message [press enter]?

## server.c (pseudo-code)
### main()
```
int  main(void)
{
  getpid()
  printf(pid)
  signal(SIGURS1, decrypt_and_stock)
  signal(SIGURS2, decrypt_and_stock)
  while (1)
    usleep(100)
}
```

### decrypt_and_stock()
```

{
  decrypt(bit)
  stock(bit_d)
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
  gestion erreurs: pas de PID ou pas de message, PID ou message invalide,...;
  while (ft_strlen(message))
    encrypt_and_send_bit_by_bit(message)
}
```

### encrypt_and_send_bit_by_bit(char *message)
```

```
