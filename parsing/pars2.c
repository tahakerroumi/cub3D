#include "../includes/cub3d.h"

void	get_infos_from_map2(char *tmp, t_global *global)
{
	if (ft_strncmp(tmp, "NO", 2) == 0)
		return (fill_elements(global, tmp, 1), free(tmp));
	if (ft_strncmp(tmp, "SO", 2) == 0)
		return (fill_elements(global, tmp, 2), free(tmp));
	if (ft_strncmp(tmp, "WE", 2) == 0)
		return (fill_elements(global, tmp, 3), free(tmp));
	if (ft_strncmp(tmp, "EA", 2) == 0)
		return (fill_elements(global, tmp, 4), free(tmp));
	if (ft_strncmp(tmp, "F", 1) == 0)
		return (fill_elements(global, tmp, 5), free(tmp));
	if (ft_strncmp(tmp, "C", 1) == 0)
		return (fill_elements(global, tmp, 6), free(tmp));
	if (ft_strlen(tmp) != 0)
	{
		free(tmp);
		free_global(global);
		error_print("Error\nmap file contains an error\n");
	}
	free(tmp);
}

void	get_infos_from_map(char **str, t_global *global)
{
	int		flag;
	int		j;
	char	*tmp;

	j = 0;
	flag = 0;
	while (str[j])
	{
		tmp = ft_strtrim(str[j]);
		if (all_elements(global) == 1)
		{
			free(tmp);
			global->index = j;
			break ;
		}
		get_infos_from_map2(tmp, global);
		j++;
	}
}

int	map_size(t_global *global)
{
	int	i;
	int	size;

	size = 0;
	i = global->index;
	while (global->map && global->map[i])
	{
		i++;
		size++;
	}
	return (size);
}
int	ft_doublepointerlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_realmap(t_global *global, int size)
{
	int	i;
	int	j;

	j = 0;
	global->real_map = malloc((size + 1) * sizeof(char *));
	if (!global->real_map)
		error_print("alloc erro\n");
	i = global->mapstart;
	while (global->map[i] && i <= global->mapend)
	{
		global->real_map[j] = ft_strdup(global->map[i]);
		i++;
		j++;
	}
	global->real_map[j] = (NULL);
}
