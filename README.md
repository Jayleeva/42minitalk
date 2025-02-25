# 42minitalk
Projet du 3ème cercle du cursus 42

# Stratégie
## Fonctionnement global
- Le "client" et le "serveur" sont en réalité juste deux programmes (= deux fichiers .c avec chacun leur main).
- Le client est exécuté avec le PID du serveur et un message en arguments, il "encrypte" le message puis utilise le PID du serveur et SIGURS1 pour envoyer "0" ou SIGURS2 pour envoyer "1" au serveur (je crois).
- Le serveur imprime son PID puis tourne à l'infini, afin d'être constamment prêt à recevoir les signaux du clients. Il "décrypte" le message envoyé par le client et l'imprime.
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
