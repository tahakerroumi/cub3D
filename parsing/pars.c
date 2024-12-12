/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:23 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:04 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

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
		error_print("check your rgb format\n");
}

void	pars(t_global *global, int ac, char **av)
{
	t_elements	*elements;
	char		**file_content;
	char		**file_content2;
	char		**file_content3;

	elements = (t_elements *)calloc(1, sizeof(t_elements));
	if (elements == NULL)
		error_print("Failed to allocate memory\n");
	if (ac != 2)
		error_print("check your arguments\n");
	if (checkextention(av[1]) == -1)
		error_print("extiontion error \n");
	file_content = map_to_doublepointer(av[1]);
	file_content2 = map_to_doublepointer(av[1]);
	file_content3 = map_to_doublepointer(av[1]);
	if (check_elements(file_content, &elements) == -1)
		error_print("the elements are not correct \n");
	elements->map = fill_map(file_content2);
	if (fill_otherelements(file_content3, &global) == -1)
		error_print("check the top of your map \n");
	global->map = doublepointercopy(elements->map);
	pars2(global);
	map_size(global);
	store_rgb(global);
}
