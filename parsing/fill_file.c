/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:43:30 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/29 15:37:22 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	fil_otherelements3(char **tmp)
{
	if (ft_doublepointerlen(tmp) != 2)
		return (-1);
	return (0);
}

void	fil_otherelements2(char **tmp, t_global **global)
{
	if (ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->no = ft_strdup(tmp[1]));
	else if (ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->so = ft_strdup(tmp[1]));
	else if (ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->we = ft_strdup(tmp[1]));
	else if (ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->ea = ft_strdup(tmp[1]));
	else if (ft_strncmp(tmp[0], "F", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->f = ft_strdup(tmp[1]));
	else if (ft_strncmp(tmp[0], "C", ft_strlen(tmp[0])) == 0)
		(fil_otherelements3(tmp), (*global)->c = ft_strdup(tmp[1]));
}

int	fill_otherelements(char **file_content3, t_global **global)
{
	char	*tmp1;
	char	**tmp;
	int		i;

	i = 0;
	while (file_content3[i])
	{
		tmp1 = ft_strtrim(file_content3[i]);
		if (tmp1[0] != '\0')
		{
			tmp = ft_split(tmp1, ' ');
			fil_otherelements2(tmp, global);
			ft_doublepointerfree(tmp);
		}
		i++;
		free(tmp1);
	}
	return (1);
}

char	**fill_map(char **str)
{
	int		i;
	int		j;
	char	**tmp;
	char	**result;
	// int		end;

	j = 0;
	tmp = malloc((ft_doublepointerlen(str) + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	i = ft_doublepointerlen(str) - 1;
	// end = i;
	while (i >= 0 && comparaison(str[i]) == -1)
		i--;
	i++;
	while (str[i])
	{
		tmp[j] = ft_strdup(str[i]);
		i++;
		j++;
	}
	tmp[j] = (NULL);
	result = doubleptr_strim(tmp, j - 1);
	ft_doublepointerfree(tmp);
	return (result);
}
