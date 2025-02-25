/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:30:31 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	call_ft_by_type(char type, va_list list, int result)
{
	char	*str;

	if (type == '%')
		result = putchar_fd_pf('%', 1, result);
	else if (type == 'c')
		result = putchar_fd_pf((char)va_arg(list, int), 1, result);
	else if (type == 's')
		result = putstr_fd_pf(va_arg(list, char *), 1, result);
	else if (type == 'd' || type == 'i')
	{
		str = ft_itoa(va_arg(list, int));
		result = putstr_fd_pf(str, 1, result);
		free (str);
	}
	else if (type == 'u' || type == 'x' || type == 'X')
		result = print_unsigned(va_arg(list, unsigned int), type, result);
	else if (type == 'p')
		result = print_pointer(va_arg(list, unsigned long long), result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		j;
	int		result;

	va_start(args, s);
	result = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == '%')
		{
			j ++;
			result = call_ft_by_type(s[j], args, result);
		}
		else
			result = putchar_fd_pf(s[j], 1, result);
		j ++;
	}
	va_end(args);
	return (result);
}
