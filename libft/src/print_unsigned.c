/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:30:31 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_toupper_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		i ++;
	}
	return (s);
}

int	print_unsigned(unsigned int u, char type, int result)
{
	char	*str;

	str = 0;
	if (u == 0)
		result = putchar_fd_pf('0', 1, result);
	else
	{
		if (type == 'u')
		{
			str = ft_itoa_base(u, 10);
			result = putstr_fd_pf(str, 1, result);
		}
		else if (type == 'x')
		{
			str = ft_itoa_base(u, 16);
			result = putstr_fd_pf(str, 1, result);
		}
		else if (type == 'X')
		{
			str = ft_itoa_base(u, 16);
			result = putstr_fd_pf(ft_toupper_str(str), 1, result);
		}
		free (str);
	}
	return (result);
}
