/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:52:46 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

char	*ft_strneww(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > (int)ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = ft_strneww(len);
	if (!str)
		return (NULL);
	j = start;
	str[len] = '\0';
	while (len-- && s[j])
		str[i++] = s[j++];
	return (str);
}

int	checkextention(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}
