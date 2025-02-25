/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:49:20 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:42:31 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int	main(void)
{
	int	c = 98;

	c = ft_toupper(c);
	printf("CUSTOM : %d\n", c);
	c = 98;
	c = toupper(c);
	printf("OFFICIAL : %d\n", c);
}*/
