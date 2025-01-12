#include "../inc/headerfile.h"

t_img	*new_img(t_minilibx *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		error_print("Error\nMalloc failed\n");
	img->img = mlx_xpm_file_to_image(data->intro, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	printf ("%d ,, %d ",img->line_length,  img->bits_per_pixel);
	return (img);
}
