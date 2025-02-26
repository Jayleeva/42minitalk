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

#include "../libft/inc/libft.h"
#include "../inc/minitalk.h"

void	send_bit_by_bit(int pid, char c)
{
	unsigned char	temp;
	int				j;

	j = 8;
	temp = c;
	while (j)
	{
		int error = 32;
		j --;
		temp = c >> j;
		if (temp % 2 == 0)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		if (error != 0)
			ft_printf("%d\n", error);
		usleep(1000);
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
		i ++;
	}
	send_bit_by_bit(pid, '\0');
	return (0);
}
