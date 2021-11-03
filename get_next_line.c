/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:00:44 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/03 19:37:40 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 42

void	if_free(char **p);
int		find_n(const char *s);
int		split_str(char *tmp, char **str, char **save, size_t location_n);
char	*read_line(int fd, char *buf, char **save, ssize_t bufsize);

char	*get_next_line(int fd)
{
	char		*str;
	char		*buf;
	static char	*save;
	ssize_t		bufsize;

	if (0 > fd || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bufsize = read(fd, buf, BUFFER_SIZE);
	if (!save && bufsize > 0)
	{
		save = ft_strdup("");
	}
	str = read_line(fd, buf, &save, bufsize);
	return (str);
}

char	*read_line(int fd, char *buf, char **save, ssize_t bufsize)
{
	char		*tmp;
	char		*str;

	str = ft_strjoin("", *save);
	if_free(save);
	if (!str)
		bufsize = 0;
	if (str && bufsize == 0 && (find_n(str) || *str == '\n'))
		split_str(ft_strdup(str), &str, save, find_n(str));
	while (bufsize > 0)
	{
		buf[bufsize] = '\0';
		tmp = ft_strjoin(str, buf);
		if (split_str(tmp, &str, save, find_n(tmp)))
			break ;
		if_free(&str);
		str = tmp;
		bufsize = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	return (str);
}

int	split_str(char *tmp, char **str, char **save, size_t location_n)
{
	if (!tmp)
	{
		if_free(str);
		if_free(save);
		return (1);
	}
	if (location_n == 0 && *tmp != '\n')
		return (0);
	if_free(str);
	*str = ft_substr(tmp, 0, location_n + 1);
	*save = ft_substr(tmp, (location_n + 1), ft_strlen(tmp) - (location_n + 1));
	if (!*str || !*save)
	{
		if_free(str);
		if_free(save);
	}
	else if (ft_strlen(*save) == 0)
		if_free(save);
	free (tmp);
	return (1);
}

int	find_n(const char *s)
{
	int	i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	if_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
}
