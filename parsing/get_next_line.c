/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:27:04 by abakhcha          #+#    #+#             */
/*   Updated: 2024/12/11 13:40:47 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rdsv(int fd, char *str)
{
	int		reader;
	char	*buf;

	reader = 1;
	if (!str)
		str = ft_calloc(1, 1);
	buf = malloc(BUFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!check_newline(str) && reader != 0)
	{
		reader = (int)read(fd, buf, BUFER_SIZE);
		if (reader == -1)
		{
			free(str);
			free(buf);
			return (NULL);
		}
		buf[reader] = '\0';
		str = str_join(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_l(char *str)
{
	int		i;
	char	*rts;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	rts = malloc(i + 2);
	if (!rts)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rts[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		rts[i++] = '\n';
	rts[i] = '\0';
	return (rts);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	if (fd < 0 || BUFER_SIZE <= 0)
		return (NULL);
	line = rdsv(fd, line);
	if (!line)
		return (NULL);
	buf = get_l(line);
	line = save(line);
	return (buf);
}
