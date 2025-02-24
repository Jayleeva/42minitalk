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
  printf("%s", pid)
  signal(SIGUSR1, handle_signal)
  signal(SIGUSR2, handle_signal)
  while (1)
    usleep(100)
}
```
### print_message(t_string **s)
```
void  print_message(t_string **s)
{
  t_string  *current;

  current = *s;
  while (current->next != NULL)
    printf("%c", current->value);
    current = current->next;
}
```


### stock_and_print(char current_char, int is_last)
```
void  stock_and_print(char current_char, int is_last)
{
  t_string  *s;
  s->next = malloc(sizeof(t_string))
  s->next->value = current_char
  s->next->next = NULL

  if is_last
    print_message(s);
}
```

### handle_signal()
```
handle_signal()
{
  typedef struct string
  {
	  int			    value;
	  struct node	*next;
  }				      t_string;

  int i;
  if signal == SIGUSR2
    current_char = signal;
  i ++;
  if i == 8
    if current_char == END_OF_MESSAGE // '\0'
      stock(&string, "\n", 1);
    else
      stock(&string, current_char, 0);
}
```


## client.c (pseudo-code)
### main()
```
int  main(int argc, char **argv)
{
  struct sigaction	sig_hook;

  gestion erreurs: pas de PID ou pas de message, PID ou message invalide,...; Si erreur, exit(0) //pid = argv[1]
  while (ft_strlen(message)) //message = argv[2], vraiment besoin de la longueur?
    encrypt_and_send_bit_by_bit(message)
}
```

### encrypt_and_send_bit_by_bit(char *message)
```
  unsigned char temp;
  while (message[i])
    j = 8
    temp = message[i]
    while (j)
        temp = message[i] >> j
        if temp % 2 == 0    // --> if (char[j] == 1 || 0), en fonction du bit 
          kill(pid, SIGUSR1) // envoie 0
        else
          kill(pid, SIGUSR2) // envoie 1
        usleep(42)
      j --;
    i ++;
```
