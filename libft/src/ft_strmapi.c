/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:20:19 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:40:33 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

/*static char	toupper_(unsigned int i, char c)
{
	printf("%d", i);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*result;

	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i ++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
	const char	s[] = "AbC";
	char		*result;

	result = ft_strmapi(s, toupper_);
	printf("\n%s", result);
}*/
