/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:43:39 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/20 15:00:21 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "../parsing/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 800

# define TILE_SIZE 64
# define FOV 60
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define M_PI 3.14159265358979323846
# define R_SPEED 0.01
# define P_SPEED 1

struct	s_global;

typedef struct s_ray
{
	double			ray_angle;
	double			distance;
	int				flag;
	double			wall_px;
	double			wall_py;
}					t_ray;

typedef struct s_key_flags
{
	int				move_forward;
	int				move_backward;
	int				move_left;
	int				move_right;
	int				rotate_right;
	int				rotate_left;
}					t_key_flags;

typedef struct s_player
{
	double			px;
	double			py;
	double			angle;
	double			fov_rad;
}					t_player;

typedef struct s_img
{
	void			*img;
	char			*pixel_ptr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;
	int				line_height;
	int				width;
	int				height;
}					t_img;

typedef struct s_minilibx
{
	void			*intro;
	void			*window;
	t_img			img;
	t_player		player;
	struct s_global	*data;
	t_ray			ray;
	t_key_flags		key;
	t_img			*no_img;
	t_img			*so_img;
	t_img			*ea_img;
	t_img			*we_img;
	int				wall_height;
}					t_minilibx;

typedef struct s_global
{
	char			**map;
	char			**tmp;
	char			**real_map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				no_flag;
	int				so_flag;
	int				we_flag;
	int				ea_flag;
	int				f_flag;
	int				c_flag;
	int				map_height;
	int				map_width;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
	int				index;
	int				mapstart;
	int				mapend;
}					t_global;

/*   parsing    */
void				parse_first_part(t_global *global, int fd);
void				error_print(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strtrim_free(char *str, char *rts);
char				*ft_strneww(size_t n);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_substr(char *s, int start, size_t len);
void				ft_doublepointerfree(char **str);
int					ft_atoi(char *str);
char				**doublepointercopy(char **map);
int					is_space(char c);
char				*ft_strtrim(char *s1);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
char				*ft_strdup(char *s1);
char				*ft_strjoin_l(char const *s1, char const *s2);
int					checkextention(char *str);
void				free_global(t_global *global);
size_t				ft_countwords(char *s, char c);
size_t				ft_getwordlen(char *s, char c);
void				ft_freearray(size_t i, char **array);
char				**ft_split(char *s, char c);
char				*my_strjoin(char const *s1, char const *s2);
char				*free_join(char *s1, char *s2);
char				*ft_strneww(size_t n);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_substr(char *s, int start, size_t len);
void				ft_doublepointerfree(char **str);
int					ft_atoi(char *str);
char				**doublepointercopy(char **map);
void				error_print(char *str);
int					is_space(char c);
char				*ft_strtrim(char *s1);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
char				*ft_strdup(char *s1);
char				*str_join(char *s1, char *s2);
void				init(t_global *global);
void				fill_elements(t_global *global, char *tmp, int x);
int					all_elements(t_global *global);
void				get_infos_from_map(char **str, t_global *global);
int					ft_doublepointerlen(char **str);
void				get_realmap(t_global *global, int size);
void				check_emptymap(t_global *global);
void				check_emptymap2(t_global *global);
void				player_exists(t_global *global);
void				check_for_unwanted_chars(t_global *global);
int					chek_walls2(t_global *global, int i, int j);
void				check_walls(t_global *global);
void				check_emptyline(t_global *global);
int					rgb_format(char *str);
void				check_rgb_format(t_global *global);
void				check_rgb_format1(t_global *global);
void				store_rgb(t_global *global);
void				check_for_textures_extension(t_global *global);
void				check_textures_extention(t_global *global);
void				check_extentions_format(t_global *global);
void				check_extentions_format2(t_global *global);
void				parse_first_part(t_global *global, int fd);
int					map_size(t_global *global);
char				**fill_map(int fd, t_global *global);

/*game initialization*/
int					mlx_intro(t_minilibx *mlx, t_global *global);
void				player_pos_dir(t_minilibx *mlx, t_global *data);
void				start_game(t_minilibx *mlx);
t_img				*new_img(t_minilibx *data, char *path);

/*keys*/
int					key_press(int keycode, void *cub3d);
int					key_release(int keycode, void *cub);
void				events(t_minilibx *mlx);
void				get_direction(t_minilibx *mlx, double *dx, double *dy);
int					check_wall(t_minilibx *mlx, double px, double py);
char				**split_once(char *s, char c);

/*Game routine*/
int					program_routine(void *cub3d);
void				world_manager(t_minilibx *mlx, int ray);
void				ray_casting(t_minilibx *mlx);
int					get_x_cord(t_minilibx *mlx);
unsigned int		get_color(int x, int y, t_img *text);
void				draw_ceiling(t_minilibx *mlx, int ray, int t_pix);
void				draw_wall(t_minilibx *mlx, int ray, int t_pix, int b_pix);
void				draw_floor(t_minilibx *mlx, int ray, int b_pix);
int					player_view_checker(float angle, double *inter,
						double *step, int is_horizon);
int					unit_circle(double angle, char c);

/*tools*/
double				angle_check(double ray);
void				player_type(t_player *player, char c);
void				my_pixel_put(int x, int y, t_img *img, int color);
int					safe_place(char **map, int x, int y);
t_img				*get_wall_texture(t_minilibx *mlx);

/*end game (free all data)*/
int					end_program(void *cub3d);
void				free_elements(t_minilibx *mlx);

void				pars2(t_global *global);
void				map_size2(t_global *global);
void				store_rgb(t_global *global);

#endif