#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void send_bit_by_bit(int pid, char c)
{
	unsigned char   temp;
	int             j;

	j = 8;
	temp = c;
	while (j)
	{
		j --;
		temp = c >> j;
		if (temp % 2 == 0)
			kill(pid, SIGUSR1); // envoie 0
		else
			kill(pid, SIGUSR2); // envoie 1
		usleep(42);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	write_error_and_exit()
{
	write(1, "Error\n", 6);
	exit (0);
}

int  main(int argc, char **argv)
{
	char	*message;
	size_t	i;
	size_t	len;
	int		pid;

	message = argv[2];
	pid = atoi(argv[1]);
	if (argc != 3)
		write_error_and_exit();
	if (kill(pid, 0) < 0)		//vérifie si le PID est valide en tentant un kill avec.
		write_error_and_exit();
	len = ft_strlen(message);
	i = 0;
	while (i < len)
	{
		send_bit_by_bit(pid, message[i]);
		i ++;
	}
	send_bit_by_bit(pid, '\0');
	return (0);
}