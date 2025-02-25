/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:27:20 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:33:16 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_;

	s_ = s;
	i = 0;
	while (i < n)
	{
		s_[i] = '\0';
		i ++;
	}
}

/*int	main(void)
{
	char	s[] = "help";
	char	s2[] = "help";
	size_t	n = 4;
	
	ft_bzero(s, n);
	bzero(s2, n);
}*/
