#include "../inc/headerfile.h"

t_img	*new_img(t_minilibx *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		error_print("Error\nMalloc failed\n");
	img->img = mlx_xpm_file_to_image(data->intro, path, &img->width,
			&img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

unsigned int	get_color(int x, int y, t_img *text)
{
	char	*pixel;

	if (x < 0 || x >= text->width || y < 0 || y >= text->height)
		return (0);
	pixel = text->addr + (y * text->line_length + x * (text->bits_per_pixel
				/ 8));
	return (*(unsigned int *)pixel);
}

int	get_x_cord(t_minilibx *mlx)
{
	if (mlx->ray.flag)
		return ((int)mlx->ray.wall_py % TILE_SIZE);
	else
		return ((int)mlx->ray.wall_px % TILE_SIZE);
}