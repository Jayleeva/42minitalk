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
//#include <stdio.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memset(ptr, 0, nelem * elsize);
	return (ptr);
}

/*int	main(void)
{
	size_t	nelem = 0;
	size_t	elsize = sizeof(int);
	char	*result;
	char	*result2;

	result = ft_calloc(nelem, elsize);
	printf("CUSTOM : %s\n", result);
	result2 = calloc(nelem, elsize);
	printf("OFFICIAL : %s\n", result2);
}*/
