/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:30 by tkerroum          #+#    #+#             */
/*   Updated: 2025/01/19 17:47:32 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*join_free(char *sta_buff, char *buff)
{
	char	*temp;

	temp = ft_strjoin(sta_buff, buff);
	free(sta_buff);
	return (temp);
}

char	*ft_read_line(int fd, char *res)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	if (!res)
	{
		res = (char *)malloc(1);
		if (!res)
			return (0);
		res[0] = 0;
	}
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(res), NULL);
		buff[bytes] = '\0';
		res = join_free(res, buff);
		if (ft_strchr_l(buff, '\n'))
			break ;
	}
	return (free(buff), res);
}

char	*print_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!buff[i])
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next(char *buff)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (0);
	}
	next = (char *)malloc(ft_strlen(buff) - i + 1);
	if (!next)
		return (0);
	i++;
	while (buff[i])
		next[j++] = buff[i++];
	next[j] = 0;
	free(buff);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = ft_read_line(fd, res);
	if (!res)
		return (0);
	line = print_line(res);
	res = get_next(res);
	return (line);
}
