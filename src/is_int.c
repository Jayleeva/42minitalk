/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:10:06 by cyglardo          #+#    #+#             */
/*   Updated: 2025/03/03 10:10:07 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if ((s[0] == '-' || s[0] == '+') && !s[1])
		return (1);
	if (s[0] == '-' || s[0] == '+')
		i ++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i ++;
	}
	return (0);
}

static int	is_bigger_than_int(int k, int i, char *s, char *num)
{
	i = k;
	while (s[i] == num[i - k] && num[i - k])
		i ++;
	if ((k == 0 && i == 9) || (k == 1 && i == 10))
	{
		if ((k == 0 && s[i] > '7') || (k == 1 && s[i] > '8'))
			return (1);
	}
	else
	{
		while (num[i - k])
		{
			if (s[i] > num[i - k])
				return (1);
			else if (s[i] < num[i - k])
				break ;
			else if (s[i] == num[i - k])
				i ++;
		}
	}
	return (0);
}

static int	is_int(char *s)
{
	int		i;
	int		k;
	char	*num;

	num = "214748364";
	k = 0;
	if (s[0] == '-')
		k = 1;
	i = 0;
	while (s[i])
		i ++;
	if ((k == 0 && i > 10) || (k == 1 && i > 11))
		return (1);
	else if ((k == 0 && i == 10) || (k == 1 && i == 11))
		if (is_bigger_than_int(k, i, s, num))
			return (1);
	return (0);
}

int	has_error(char *s)
{
	if (is_number(s) == 1)
		return (1);
	if (is_int(s) == 1)
		return (1);
	return (0);
}
