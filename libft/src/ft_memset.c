/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:54 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:36:03 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_;

	i = 0;
	b_ = b;
	while (i < len)
	{
		b_[i] = (unsigned char)c;
		i ++;
	}
	return (b);
}

/*int	main(void)
{
	char	b[6] = "asd";
	char	b2[6] = "asd";
	int		c = 65;
	size_t	len = 5;

	printf("CUSTOM = %s\n", ft_memset(b, c, len));
	printf("OFFICIAL = %s\n", memset(b2, c, len));
}*/
