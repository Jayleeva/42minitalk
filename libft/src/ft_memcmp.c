/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:22 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:35:11 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char	*s1_;
	char	*s2_;

	s1_ = (char *)s1;
	s2_ = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		i ++;
	}
	return (0);
}

/*int	main(void)
{
	const char	s1[6] = "Hello";
	const char	s2[6] = "Hell!";
	size_t		n = 5;
	int			result;
	
	result = ft_memcmp(s1, s2, n);
	printf("CUSTOM : %d\n", result);
	result = memcmp(s1, s2, n);
	printf("OFFICIAL : %d\n", result);
}*/
