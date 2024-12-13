/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:11:41 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/13 20:21:26 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/headerfile.h"

void dbarray_free(char **str1, char **str2, char **str3)
{
    if(str1)
        free(str1);
    if(str2)
        ft_doublepointerfree(str2);
    if(str3)
        ft_doublepointerfree(str3);
}