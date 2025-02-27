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

void	send_bit_by_bit(int pid, char c)
{
	unsigned char	temp;
	int				j;

	j = 8;
	temp = c;
	while (j)
	{
		if (can_send)
		{
			j --;
			temp = c >> j;
			if (temp % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			can_send = 0;
			signal(SIGUSR2, handle_signal_client);
			//usleep(1000);
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
	if (kill(pid, 0) < 0)
		write_error_and_exit();
	len = ft_strlen(message);
	i = 0;
	while (i < len)
	{
		send_bit_by_bit(pid, message[i]);
		usleep(1000);
		i ++;
	}
	send_bit_by_bit(pid, '\0');
	return (0);
}
