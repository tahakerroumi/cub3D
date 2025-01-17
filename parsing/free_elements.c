/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:43 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/17 11:09:48 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void    destroy_textures(t_minilibx *mlx)
{
    if (mlx->ea_img)
        mlx_destroy_image(mlx->intro, mlx->ea_img->img);
    if (mlx->so_img)
        mlx_destroy_image(mlx->intro, mlx->so_img->img);
    if (mlx->we_img)
        mlx_destroy_image(mlx->intro, mlx->we_img->img);
    if (mlx->no_img)
        mlx_destroy_image(mlx->intro, mlx->no_img->img);
    else
        return ;
}

void    free_textures(t_minilibx *mlx)
{
    destroy_textures(mlx);
    if (mlx->ea_img)
        free(mlx->ea_img);
    if (mlx->so_img)
        free(mlx->so_img);
    if (mlx->we_img)
        free(mlx->we_img);
    if (mlx->no_img)
        free(mlx->no_img);
    else
        return ;
}

void	free_elements(t_minilibx *mlx)
{
    free_textures(mlx);
    ft_doublepointerfree(mlx->data->map);
    free(mlx->data);
    if (mlx->intro)
    {
        mlx_destroy_display(mlx->intro);
        free(mlx->intro);
    }
}
