/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:19:26 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:37:52 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i ++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[7] = "ABCDEF";
	int			c = 68;
	char		*result;
   
	result = ft_strchr(s, c);
	printf("CUSTOM : %s\n", result);
	result = strchr(s, c);
	printf("OFFICIAL : %s\n", result);
}*/
