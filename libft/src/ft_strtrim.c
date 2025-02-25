/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:48 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 09:25:17 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		len;
	char		*result;

	end = ft_strlen(s1);
	start = 0;
	while (is_in_set(set, s1[start]) == 1)
		start ++;
	if (start >= end)
		return (ft_strdup(""));
	while (is_in_set(set, s1[end -1]) == 1)
		end --;
	len = end - start;
	result = ft_substr(s1, start, len);
	return (result);
}

/*int	main(void)
{
	const char	s1[] = "  \t \t \n   \n\n\n\t";
	const char	set[] = " \n\t";
	char		*result;

	result = ft_strtrim(s1, set);
	printf("\n%s", result);
}*/
