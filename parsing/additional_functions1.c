/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:53:19 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 19:31:36 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	atoiii(char p)
{
	if (p != ' ' && p != '\n' && p != '\t' && p != '\v' && p != '\f'
		&& p != '\r' && (p < '0' || p > '9'))
		error_print("Error\nmixed int and chars\n");
}

int	ft_atoi(char *str)
{
	int	res;
	int	negative;
	int	i;

	negative = 1;
	i = 0;
	res = 0;
	while (str[i])
	{
		atoiii(str[i]);
		i++;
	}
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

char	**doublepointercopy(char **map)
{
	int		i;
	char	**test;

	i = 0;
	while (map[i])
		i++;
	test = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		test[i] = ft_strdup(map[i]);
		i++;
	}
	test[i] = NULL;
	ft_doublepointerfree(map);
	return (test);
}

void	error_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit(1);
}

int	is_space(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}
