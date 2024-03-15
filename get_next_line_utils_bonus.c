/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:00:06 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/13 15:52:25 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*legge_la_linea(int fd, char *left_line)
{
	char		*buf;
	int			number_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	number_byte = 1;
	while (!ft_strachr(left_line, '\n') && number_byte != 0)
	{
		number_byte = read(fd, buf, BUFFER_SIZE);
		if (number_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[number_byte] = '\0';
		left_line = ft_strjoint(left_line, buf);
	}
	free(buf);
	return (left_line);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	*left_line[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_line[fd] = legge_la_linea(fd, left_line[fd]);
	if (!left_line[fd])
		return (NULL);
	linea = prendi(left_line[fd]);
	left_line[fd] = checkpoint(left_line[fd]);
	return (linea);
}
