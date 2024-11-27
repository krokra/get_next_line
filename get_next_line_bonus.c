/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:31:36 by psirault          #+#    #+#             */
/*   Updated: 2024/11/27 08:49:27 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stock(int fd, char *buffer, char *stock)
{
	ssize_t	read_value;

	read_value = 1;
	if (!stock || stock == NULL)
		stock = (ft_strdup(""));
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_value] = 0;
		stock = ft_strjoin(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[4096];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stock[fd]);
		free(buffer);
		stock[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stock[fd] = fill_stock(fd, buffer, stock[fd]);
	if (*stock[fd] == 0)
	{
		free(stock[fd]);
		return (stock[fd] = 0);
	}
	line = get_line_from_stock(stock[fd], line);
	stock[fd] = update_stock(stock[fd]);
	return (line);
}

char	*update_stock(char *stock)
{
	char	*updated_stock;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (stock == NULL)
		return (NULL);
	while (stock[len] != '\n' && stock[len] != '\0')
		len++;
	if (stock[len] == '\n')
		len++;
	updated_stock = (char *)malloc((ft_strlen(stock) - len + 1) * sizeof(char));
	if (!updated_stock)
		return (NULL);
	while (stock[i + len] != '\0')
	{
		updated_stock[i] = stock[i + len];
		i++;
	}
	free(stock);
	updated_stock[i] = 0;
	return (updated_stock);
}

char	*get_line_from_stock(char *stock, char *line)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = 0;
	if (stock == NULL)
		return (NULL);
	while (stock[line_len] != '\n' && stock[line_len] != '\0')
		line_len++;
	if (stock[line_len] == '\n')
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = 0;
	return (line);
}
/*
#include <stdio.h>
int main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("GNL 1: %s", get_next_line(fd));
	printf("GNL 2: %s", get_next_line(fd));
	printf("GNL 3: %s", get_next_line(fd));
	printf("GNL 4: %s", get_next_line(fd));
	printf("GNL 5: %s", get_next_line(fd));
	printf("GNL 6: %s", get_next_line(fd));
	printf("GNL 7: %s", get_next_line(fd));
	printf("GNL 8: %s", get_next_line(fd));
	printf("GNL 9: %s", get_next_line(fd));
	close(fd);
}*/
