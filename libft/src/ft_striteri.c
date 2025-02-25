/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:34 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:40:55 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	toupper_(unsigned int i, char *str)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
}

/*int	main(void)
{
	char	s[] = "aBc";

	ft_striteri(s, toupper_);
}*/
