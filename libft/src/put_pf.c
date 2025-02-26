/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:30:31 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putchar_fd_pf(char c, int fd, int result)
{
	write(fd, &c, 1);
	result ++;
	return (result);
}

int	putstr_fd_pf(char *s, int fd, int result)
{
	int	i;

	if (s == NULL)
	{
		result = putstr_fd_pf("(null)", 1, result);
		return (result);
	}
	i = 0;
	while (s[i])
	{
		result = putchar_fd_pf(s[i], fd, result);
		i ++;
	}
	return (result);
}
