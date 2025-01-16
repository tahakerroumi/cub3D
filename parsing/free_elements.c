/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:43 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/16 16:38:02 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headerfile.h"

void    free_textures(t_minilibx *mlx)
{
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

void    free_elements(t_minilibx *mlx)
{
    ft_doublepointerfree(mlx->data->map);
    free_textures(mlx);
    free(mlx->data);
	free(mlx->intro);
}
