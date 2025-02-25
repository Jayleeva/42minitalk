/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:01:33 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:42:03 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char	*result;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	result = NULL;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			result = (char *)&s[i];
		i ++;
	}
	return (result);
}

/*int	main(void)
{
	const char	s[7] = "CBDCF";
	int			c = 67;
	char		*result;
   
	result = ft_strrchr(s, c);
	printf("CUSTOM : %s\n", result);
	result = strrchr(s, c);
	printf("OFFICIAL : %s\n", result);	
}*/
