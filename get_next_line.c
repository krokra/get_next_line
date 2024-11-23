/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:50:18 by marvin            #+#    #+#             */
/*   Updated: 2024/11/23 15:50:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_through_line(char *line_buf)
{
	while (*line_buf != '\0' || *line_buf != '\n')

}

char    *get_next_line(int fd)
{
    static char	*static_line_buffer;
	char	*line;
	int		done;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	done = 1;
	line = NULL;
}