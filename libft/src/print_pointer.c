/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:43:53 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(unsigned long long p, int result)
{
	char	*str;

	if (p == 0)
		result = putstr_fd_pf("0x0", 1, result);
	else
	{
		result = putstr_fd_pf("0x", 1, result);
		str = ft_itoa_base(p, 16);
		result = putstr_fd_pf(str, 1, result);
		free (str);
	}
	return (result);
}
