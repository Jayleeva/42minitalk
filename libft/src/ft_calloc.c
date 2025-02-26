/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:32 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:33:30 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memset(ptr, 0, nelem * elsize);
	return (ptr);
}
