/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:01:51 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:21:20 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = (char *)malloc((len +1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		result[j] = s[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}

/*int	main(void)
{
	char			s[] = "ah";
	unsigned int	start = 3;
	size_t			len = 3;
	char			*result;

	result = ft_substr(s, start, len);
	printf("\n%s", result);
}*/
