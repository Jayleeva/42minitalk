/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:43 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:34:41 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	get_nelem(int n)
{
	int	sign;
	int	nelem;

	nelem = 1;
	if (n < 0)
	{
		sign = 1;
		if (n == -2147483648)
			n ++;
		n = n * -1;
	}
	else
		sign = 0;
	while (n > 9)
	{
		nelem ++;
		n = n / 10;
	}
	return (nelem + sign);
}

static int	get_temp(int n)
{
	int	temp;

	temp = n;
	if (n < 0)
	{
		if (n == -2147483648)
			temp ++;
		temp = temp * -1;
	}
	return (temp);
}

char	*ft_itoa(int n)
{
	int		nelem;
	int		i;
	int		temp;
	char	*result;

	nelem = get_nelem(n);
	result = (char *)malloc((nelem + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	temp = get_temp(n);
	i = nelem -1;
	while (i > 0)
	{
		result[i] = (temp % 10) + '0';
		temp = temp / 10;
		i --;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = (temp % 10) + '0';
	if (n == -2147483648)
		result[nelem -1] = '8';
	result[nelem] = '\0';
	return (result);
}

/*int	main(void)
{
	int		n = 156;
	char	*result;

	result = ft_itoa(n);
	printf("%s", result);
}*/
