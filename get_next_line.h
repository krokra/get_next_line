/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:00:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/23 16:00:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

int     ft_strlen(char *str);
char	*ft_strjoin(char  *s1, char *s2);
char	*ft_strchr(char *s, int c);
char    *ft_strdup(char *str);
char	*ft_substr(char  *s, unsigned int start, size_t len);
char    *get_next_line(int fd);
char	*get_line_from_stock(char *stock, char *line);
char	*update_stock(char * stock);
char	*fill_stock(int fd, char *buffer, char *stock);

#endif