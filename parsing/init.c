#include "../includes/cub3d.h"

void	init2(t_global *global)
{
	global->map_height = 0;
	global->map_width = 0;
	global->floor_red = 0;
	global->floor_green = 0;
	global->floor_blue = 0;
	global->ceiling_red = 0;
	global->ceiling_green = 0;
	global->ceiling_blue = 0;
	global->no_flag = 0;
	global->so_flag = 0;
	global->we_flag = 0;
	global->ea_flag = 0;
	global->f_flag = 0;
	global->c_flag = 0;
	global->index = 0;
	global->mapstart = 0;
}

void	init(t_global *global)
{
	global->real_map = NULL;
	global->map = NULL;
	global->no = NULL;
	global->so = NULL;
	global->we = NULL;
	global->ea = NULL;
	global->f = NULL;
	global->c = NULL;
	global->no_path = NULL;
	;
	global->so_path = NULL;
	global->we_path = NULL;
	global->ea_path = NULL;
	init2(global);
}