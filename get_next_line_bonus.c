/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:00:44 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/23 13:17:42 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **p);
int		split_by_n(char *total, char **line, char **save, char *location_n);
char	*get_one_line(int fd, char *buf, char **save, ssize_t bufsize);
char	*ft_strchr_dx(const char *s, int c);

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep_lines[FOPEN_MAX] = {NULL};
	ssize_t		bufsize;

	if (0 > fd || fd > FOPEN_MAX - 1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
	{
		ft_free(&keep_lines[fd]);
		return (NULL);
	}
	bufsize = read(fd, buf, BUFFER_SIZE);
	if (keep_lines[fd] == NULL && bufsize > 0)
		keep_lines[fd] = ft_strdup("");
	return (get_one_line(fd, buf, &keep_lines[fd], bufsize));
}

char	*get_one_line(int fd, char *buf, char **save, ssize_t bufsize)
{
	char		*total;
	char		*line;

	line = ft_strjoin("", *save);
	ft_free(save);
	if (line == NULL)
		bufsize = 0;
	else if (line && bufsize == 0)
		split_by_n(line, &line, save, ft_strchr_dx(line, '\n'));
	while (bufsize > 0)
	{
		buf[bufsize] = '\0';
		total = ft_strjoin(line, buf);
		if (split_by_n(total, &line, save, ft_strchr_dx(total, '\n')))
			break ;
		ft_free(&line);
		line = total;
		bufsize = read(fd, buf, BUFFER_SIZE);
	}
	if (bufsize == -1)
		ft_free (&line);
	ft_free (&buf);
	return (line);
}

int	split_by_n(char *total, char **line, char **save, char *location_n)
{
	if (total == NULL)
	{
		ft_free(line);
		return (1);
	}
	if (location_n == NULL)
		return (0);
	if (total != *line)
		ft_free(line);
	*line = ft_substr(total, 0, ft_strlen(total) - ft_strlen(location_n + 1));
	*save = ft_strdup(location_n + 1);
	if (*line == NULL || *save == NULL)
	{
		ft_free(line);
		ft_free(save);
	}
	else if (ft_strlen(*save) == 0)
		ft_free(save);
	ft_free (&total);
	return (1);
}

char	*ft_strchr_dx(const char *s, int c)
{
	size_t	i;
	char	*ss;

	if (s == NULL)
		return (NULL);
	ss = (char *)s;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == (char)c)
			return (&ss[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&ss[i]);
	return (NULL);
}

void	ft_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
}
