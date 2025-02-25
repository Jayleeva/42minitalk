/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:13:42 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:33:43 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) != 0) || (ft_isdigit(c) == 1))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	i = 'Z';
	int	result;

	result = ft_isalnum(i);
	printf("CUSTOM = %d\n", result);
	result = isalnum(i);
	printf("OFFICIAL = %d\n", result);
}*/
