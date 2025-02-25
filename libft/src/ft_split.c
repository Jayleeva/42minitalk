/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:33:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/23 12:47:08 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

static char	*fill_tab(const char *array, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (array[i] != c && array[i])
		i++;
	s = ft_substr(array, 0, i);
	return (s);
}

static int	get_nelem(char const *s, char c)
{
	int	nelem;
	int	i;

	i = 0;
	nelem = 0;
	while (s[i])
	{
		if ((i == 0 || s[i -1] == c) && s[i] != c)
			nelem ++;
		i ++;
	}
	return (nelem);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc((get_nelem(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < get_nelem(s, c) && s[j])
	{
		if (s[j] != c)
		{
			tab[i] = fill_tab(s + j, c);
			if (tab[i] == NULL)
				return (free_tab(tab), NULL);
			j = j + ft_strlen(tab[i]);
			i ++;
		}
		else
			j++;
	}
	tab[i] = NULL;
	return (tab);
}

/*int	main(void)
{
	char const	s[] = "Salut ca va?||-Non et toi?|-Bien merci.|||-Cool.";
	char		c = '|';
	char		**result;
	int			i;

	result = ft_split(s, c);
	i = 0;
	while (result[i])
	{
		printf("\n%s", result[i]);
		i ++;
	}
}*/
