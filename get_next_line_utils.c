/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:52:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/23 15:52:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char    *tab;
    int     i;

    i = 0;
    tab = (char *)malloc(sizeof(tab) * (ft_strlen(str) + 1));
    while (str[i])
    {
        tab[i] = str[i];
        i++;
    }
    return (tab);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if ((char)c == '\0' && *s == '\0')
		return (s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	tab = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tab)
	{
		return (0);
	}
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		tab[j] = s2[i];
		j++;
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
	{
		return (ft_strdup(""));
	}
	if (slen - start < len)
		len = slen - start;
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (!tab || !s)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[len] = '\0';
	return (tab);
}