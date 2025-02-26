/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:24:07 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:39:15 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (j < (dstsize - i -1) && src[j])
	{
		dest[i + j] = src[j];
		j ++;
	}
	if (dstsize != 0)
		dest[i + j] = '\0';
	j = ft_strlen(src);
	return (i + j);
}
