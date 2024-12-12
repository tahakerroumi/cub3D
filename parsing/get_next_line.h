/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:28:13 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/16 22:03:48 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFER_SIZE
#  define BUFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		check_newline(char *str);
char	*get_next_line(int fd);
char	*str_join(char *s1, char *s2);
char	*get_l(char *save);
char	*save(char *save);
void	*ft_calloc(size_t s, size_t size);

#endif