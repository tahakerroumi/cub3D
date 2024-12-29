/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:58:08 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/29 15:37:22 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

int	elements_are_mixed(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(str, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(str, "WE", 2) == 0)
		return (1);
	else if (ft_strncmp(str, "EA", 2) == 0)
		return (1);
	else if (str[0] == 'F' && str[1] == '\0')
		return (1);
	else if (str[0] == 'C' && str[1] == '\0')
		return (1);
	return (-1);
}

void	compare_texture(char **str, t_elements **elements)
{
	if (ft_strncmp(str[0], "NO", ft_strlen(str[0])) == 0)
		(*elements)->no += 1;
	else if (ft_strncmp(str[0], "SO", ft_strlen(str[0])) == 0)
		(*elements)->so += 1;
	else if (ft_strncmp(str[0], "WE", ft_strlen(str[0])) == 0)
		(*elements)->we += 1;
	else if (ft_strncmp(str[0], "EA", ft_strlen(str[0])) == 0)
		(*elements)->ea += 1;
}

void	compare_floorcellingcolor(char **str, t_elements **elements)
{
	if (ft_strncmp(str[0], "F", ft_strlen(str[0])) == 0)
		(*elements)->f += 1;
	if (ft_strncmp(str[0], "C", ft_strlen(str[0])) == 0)
		(*elements)->c += 1;
}

int	check_elementsnumber(t_elements *elements)
{
	if (elements->ea == 1
		&& elements->we == 1
		&& elements->so == 1
		&& elements->no == 1
		&& elements->f == 1
		&& elements->c == 1)
		return (1);
	return (-1);
}
