/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:58:01 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/18 14:46:31 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int chekerr(char **str)
{
	int i;
	
	i = 0;
	char **tmp;
	while(str[i])
	{
		tmp = ft_split(str[i] ,' ');
		if(ft_doublepointerlen(tmp)!= 1)
		{
			ft_doublepointerfree(tmp);
			return (-1);
		}
		ft_doublepointerfree(tmp);
		i++;
	}
	return(1);
}

char **split_once(char *s, char c)
{
    char **result;
    size_t i;

	i = 0;
    if (!s)
        return (NULL);
    result = (char **)malloc(sizeof(char *) * 3);
    if (!result)
        return (NULL);
    while (s[i] && s[i] != c)
        i++;
    result[0] = strndup(s, i);
    if (!result[0])
        return (free(result),NULL);
    if (s[i] == c)
        result[1] = strdup(s + i + 1);
    else
        result[1] = strdup("");
    if (!result[1])
    {
        free(result[0]);
        return (free(result),NULL);
    }
    result[2] = NULL;
    return result;
}

int	ft_doublepointerlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_elements(char **map, t_elements **elements)
{
	char	*tmp1;
	char	**tmp;
	int		i;

	i = 0;
	**elements = (typeof(**elements)){0};
	while (map[i])
	{
		tmp1 = ft_strtrim(map[i]);
		if ( tmp1[0] != '\0')
		{
			if(tmp1[0] != 'F' && tmp1[0] != 'C')
				tmp = ft_split(tmp1, ' ');
			else
				tmp = split_once(tmp1, ' ');
			if (elements_are_mixed(tmp[0]) == -1)
			{
				free(tmp1);
				ft_doublepointerfree(tmp);
				break ;
			}
			compare_texture(tmp, elements);
			compare_floorcellingcolor(tmp, elements);
			ft_doublepointerfree(tmp);
		}
		i++;
		free(tmp1);
	}
	return (check_elementsnumber(*elements));
}

void	check_fc2(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->c, ',');
	if (ft_doublepointerlen(tmp) != 3 || chekerr(tmp) == -1)
	{
		ft_doublepointerfree(tmp);
		free(global->c);
		free(global->f);
		free(global->no);
		free(global->we);
		free(global->so);
		free(global->ea);
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nelements problem\n");
	}
	if (ft_atoi(tmp[0]) < 0
		|| ft_atoi(tmp[0]) > 255
		|| ft_atoi(tmp[1]) < 0
		|| ft_atoi(tmp[1]) > 255
		|| ft_atoi(tmp[2]) < 0
		|| ft_atoi(tmp[2]) > 255)
	{
		ft_doublepointerfree(tmp);
		free(global->c);
		free(global->f);
		free(global->no);
		free(global->we);
		free(global->so);
		free(global->ea);
		ft_doublepointerfree(global->map);
		free(global);
		error_print("Error\nelements problem\n");
	}
	ft_doublepointerfree(tmp);
}

void	check_fc(t_global *global)
{
	char	**tmp2;

	check_fc2(global);
	tmp2 = ft_split(global->f, ',');
	if (ft_doublepointerlen(tmp2) != 3 || chekerr(tmp2) == -1)
	{
		ft_doublepointerfree(tmp2);
		ft_doublepointerfree(global->map);
		free(global->c);
		free(global->f);
		free(global->no);
		free(global->we);
		free(global->so);
		free(global->ea);
		free(global);
		error_print("Error\nelements problem\n");
	}
	if (ft_atoi(tmp2[0]) < 0
		|| ft_atoi(tmp2[0]) > 255
		|| ft_atoi(tmp2[1]) < 0
		|| ft_atoi(tmp2[1]) > 255
		|| ft_atoi(tmp2[2]) < 0
		|| ft_atoi(tmp2[2]) > 255)
	{
		free(global->c);
		free(global->f);
		free(global->no);
		free(global->we);
		free(global->so);
		free(global->ea);
		ft_doublepointerfree(global->map);
		free(global);
		ft_doublepointerfree(tmp2);
		error_print("Error\nelements problem\n");
	}
	ft_doublepointerfree(tmp2);
}
