/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:21:05 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:39:26 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (len +1 < dstsize)
		ft_memcpy(dest, src, len +1);
	else if (dstsize != 0)
	{
		ft_memcpy(dest, src, dstsize -1);
		dest[dstsize -1] = '\0';
	}
	return (len);
}
