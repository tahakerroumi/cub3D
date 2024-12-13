/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:35 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/13 10:42:10 by tkerroum         ###   ########.fr       */
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

# include "../parsing/get_next_line.h"

#define LENGHT 1250
#define WIDTH 550
#define TILE_SIZE 30

typedef struct	s_img
{
	void	*img;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct	s_minilibx
{
	void	*intro;
	void	*window;
	t_img	img;
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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		map_height;
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

#endif