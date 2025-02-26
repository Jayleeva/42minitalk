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
