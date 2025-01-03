/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:35 by abakhcha          #+#    #+#             */
/*   Updated: 2025/01/01 03:09:15 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFILE_H
# define HEADERFILE_H

// #include <mlx.h>
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

# include "../parsing/get_next_line.h"

#define	WIDTH 		800
#define	HEIGHT 		800

#define TILE_SIZE 	44
#define	FOV 		60

#define W 			119
#define A 			97
#define S 			115
#define D 			100
#define LEFT 		65361
#define RIGHT 		65363
#define	ESC			65307

#define M_PI		3.14159265358979323846
#define R_SPEED 	0.004
#define P_SPEED 	0.2

struct s_global;

typedef struct	s_ray
{
	double	ray_angle;
	double	distance;
	int		flag;
}				t_ray;

typedef struct	s_key_flags
{
	int	move_forward;
	int	move_backward;
	int	move_left;
	int	move_right;
	int	rotate_right;
	int	rotate_left;
}				t_key_flags;

typedef struct	s_player
{
	double	px; // position x in pixels (in 2d adding the tiles)
	double	py; // position y in pixels (in 2d adding the tiles)
	double	angle; // angle that defines the direction of the player view
	double	dir_x;
	double	dir_y;
	double	fov_rad; // field of view but in radian
}				t_player;

typedef struct	s_img
{
	void	*img;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_HEIGHT;
	int		endian;
}				t_img;

typedef struct	s_minilibx
{
	void			*intro;
	void			*window;
	t_img			img;
	t_player		player;
	struct s_global	*data;
	t_ray			ray;
	t_key_flags		key;
}				t_minilibx;

int		checkextention(char *av);
void	error_print(char *str);
char	*ft_substr(char *s, int start, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *s, char c);
char	*ft_strtrim(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
int		ft_atoi(char *str);
char	**doublepointercopy(char **map);
char	**map_to_doublepointer(char *av);

typedef struct s_elements
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	char	**map;
}	t_elements;

typedef struct s_global
{
	char	**map;
	int		map_x; // player x position in the map
	int		map_y; // player y position in the map
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		map_height ;
	int		map_width;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
}	t_global;


// void	fill_elements(char **str, t_elements **elements, int type);
int		check_elements(char **map, t_elements **elements);
int		comparaison(char *str);
int		ft_doublepointerlen(char **str);
int		ft_doublepointerlen(char **str);
void	check_for_textures_extension(t_global *global);
void	check_for_unwanted_chars(t_global *global);
void	check_walls(t_global *global);
void	palyer_exists(t_global *global);
void	ft_doublepointerfree(char **str);
void	check_textures_extention(t_global *global);
void	check_fc(t_global *global);
char	**fill_map(char **str);
int		fill_otherelements(char **file_content3, t_global **global);
char	**doubleptr_strim(char **str, int end);
void	pars(t_global *global, int ac, char **av);
int		rgb_format(char *str);
void	compare_floorcellingcolor(char **str, t_elements **elements);
int		elements_are_mixed(char *str);
int		check_elementsnumber(t_elements *elements);
void	compare_texture(char **str, t_elements **elements);
void	map_size(t_global *global);
void	store_rgb(t_global *global);

/*game initialization*/
void	start_game(t_minilibx *mlx);
int		mlx_intro(t_minilibx *mlx, t_global *global);
void 	draw_player(t_minilibx *mlx);
void	my_pixel_put(int x, int y, t_img *img, int color);
void	draw_tile(int i, int j, t_img *img, int color);
void	pixel_manager(t_minilibx *mlx, t_global *data, int i, int j);
void	create_map(t_minilibx *mlx, t_global *data);
void 	player_finder(t_minilibx *mlx, t_global *data);
int		key_routine(int keycode, t_minilibx *mlx);
// void    draw_player_view(t_minilibx *mlx);
int unit_circle(double angle, char c);
int inter_check(float angle, double *inter, double *step, int is_horizon);
int	key_press(int keycode, void *cub);
int	key_release(int keycode, void *cub);
double	angle_check(double	ray);
void	keys_init(t_minilibx *mlx);
void player_pos_dir(t_minilibx *mlx, t_global *data);
double	angle_check(double	ray);
void	player_type(t_player *player, char c);
void	my_pixel_put(int x, int y, t_img *img, int color);
void draw_ray(t_minilibx *mlx, double ray_angle, double distance);
int	wall_hit(t_minilibx *mlx, double dx, double dy);
double	get_vertical(t_minilibx *mlx, double ray);
double	get_horizontal(t_minilibx *mlx, double ray);
void events(t_minilibx *mlx);

#endif