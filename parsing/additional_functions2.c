/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:53:33 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/18 14:23:15 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void	ft_doublepointerfree(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	negative;
	int i;

	negative = 1;
	i = 0;
	res = 0;
	while(str[i])
	{
		// printf();
		if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r' && (str[i] < '0' || str[i] > '9'))
			error_print("Error\nmixed int and chars\n");
		i++;
	}
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
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
