/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:56 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:41:20 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((char)s1[i] - (char)s2[i]);
		i ++;
	}
	return (0);
}

/*int main(void)
{
	const char  s1[6] = "Hello";
	const char  s2[6] = "Hell!";
	size_t		n = 5;
	int result;

	result = ft_strncmp(s1, s2, n);
	printf("CUSTOM : %d\n", result);
	result = strncmp(s1, s2, n);
	printf("OFFICIAL : %d\n", result);
}*/
