/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:55:26 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/29 15:37:22 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	is_space(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

char	*ft_strtrim(char *s1)
{
	size_t	start;
	size_t	end;
	char	*dup;

	if (!s1)
		return (NULL);
	start = 0;
	if (!s1[start])
	{
		dup = ft_strdup("");
		return (dup);
	}
	while (s1[start] && is_space(s1[start]) != 0)
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && is_space(s1[end]) != 0)
		end--;
	dup = (char *)malloc(end - start + 2);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1 + start, end - start + 2);
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i < (dstsize - 1)) && src[i] && dstsize > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	s2 = (char *)malloc((size + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
