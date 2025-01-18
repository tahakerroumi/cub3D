/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:52:42 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/18 13:09:21 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

char	**map_to_doublepointer(char *av)
{
	char	*s1;
	char	*l;
	int		fd;
	char	**map;

	fd = open(av, O_RDWR);
	if (fd == -1 || !fd)
		error_print("Error::can not open the file\n");
	l = get_next_line(fd);
	if (l == NULL)
		error_print("Error\nempty file \n");
	s1 = calloc(1, 1);
	while (l != NULL)
	{
		if (l[0] == '\n')
			s1 = str_join(s1, "  \n");
		else
			s1 = str_join(s1, l);
		free(l);
		l = get_next_line(fd);
	}
	map = ft_split(s1, '\n');
	free(s1);
	close(fd);
	return (map);
}

int	rgb_format(char *str)
{
	int	def;
	int	i;

	i = 1;
	def = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else if (str[i] == ','
			&& ((str[i - 1] >= '0'
					&& str[i - 1] <= '9')
				|| str[i - 1] == ' '))
		{
			def += 1;
			i++;
		}
		else
			break ;
	}
	if (str[i] == '\0' && def == 2)
		return (1);
	return (-1);
}

void	pars2(t_global *global)
{
	check_for_textures_extension(global);
	check_for_unwanted_chars(global);
	check_fc(global);
	check_textures_extention(global);
	check_walls(global);
	palyer_exists(global);
	if (rgb_format(global->c) == -1 || rgb_format(global->f) == -1)
	{
		free(global->c);
		free(global->f);
		free(global->ea);
		free(global->no);	
		free(global->so);	
		free(global->we);		
		free(global->map);
		free(global);
		error_print("check your rgb format\n");
	}
}
