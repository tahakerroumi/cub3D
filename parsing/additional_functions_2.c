/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:53:13 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 17:53:14 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**split(char *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, ft_getwordlen(s + j, c));
		if (!*(array + i))
		{
			ft_freearray(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1 == 0)
		s1 = "";
	x = 0;
	y = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (x < (int)ft_strlen(s1))
	{
		x[str] = x[s1];
		x++;
	}
	while (y < (int)ft_strlen(s2))
		x++[str] = y++[s2];
	x[str] = '\0';
	return (str);
}

char	*free_join(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp1;

	tmp = s1;
	tmp1 = my_strjoin(tmp, s2);
	free(s1);
	return (tmp1);
}
