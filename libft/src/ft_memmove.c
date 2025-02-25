/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:32:03 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:35:49 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_;
	const unsigned char	*src_;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (src < dest)
			dest_[n - i - 1] = src_[n - i -1];
		else
			dest_[i] = src_[i];
		i ++;
	}
	return (dest);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	char		dest2[7] = "abcdef";
	const char	src[7] = "ahahah";
	size_t		n = 4;
	char		*result;

	result = ft_memmove(dest, src, n);	
	printf("CUSTOM : %s\n", result);
	result = memmove(dest2, src, n);
	printf("OFFICIAL : %s\n", result);
}*/
