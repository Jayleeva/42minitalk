/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   client.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/26 10:38:03 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/26 10:38:04 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

int	can_send = 1;

void    handle_signal_client(int sig)
{
	if (sig == SIGUSR2)
		can_send = 1;
}

void	send_bit_by_bit(int pid, unsigned char c) // besoin d'une temporaire!! sinon n'imprime rien voir plante. Pas compris pourquoi cela dit. Les vérifications si kill a bien fontionné amènent à des User defined signal 2 venus a priori du serveur; on constate aussi que l'envoi du signal est toujours réussi.
{
	unsigned char	temp;
	int				j;

	j = 8;
	temp = c;
	while (j)
	{
		if (can_send)
		{
			can_send = 0;
			j --;
			temp = c >> j;
			if (temp % 2 == 0)
					kill(pid, SIGUSR1);
			else
					kill(pid, SIGUSR2);
			/*if (temp % 2 == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					kill(pid, SIGUSR1);
					write(1, "\n!!ERROR SIGUSR1!!\n", 19);
				}
				else
					write(1, "\n!!SIGUSR1 WORKED!!\n", 20);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					kill(pid, SIGUSR2);
					write(1, "\n!!ERROR SIGUSR2!!\n", 19);
				}
				else
					write(1, "\n!!SIGUSR2 WORKED!!\n", 20);
			}*/
			signal(SIGUSR2, handle_signal_client);
		}
	}
}

void	write_error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	main(int argc, char **argv)
{
	char	*message;
	size_t	i;
	size_t	len;
	int		pid;

	if (argc != 3)
		write_error_and_exit();
	if (has_error(argv[1]) == 1)
		write_error_and_exit();
	message = argv[2];
	pid = atoi(argv[1]);
	if (kill(pid, 0) == -1) //si l'argument sig est mis à 0, aucune signal n'est envoyé mais l'accès au PID est vérifié. Ne devrait donc pas interférer avec le reste.
		write_error_and_exit();
	len = ft_strlen(message);
	i = 0;
	while (i < len)
	{
		send_bit_by_bit(pid, message[i]);
		usleep(100);
		i ++;
	}
	send_bit_by_bit(pid, '\0');
	return (0);
}
