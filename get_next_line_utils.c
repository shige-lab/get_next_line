/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:45:03 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/03 19:33:09 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!total)
		return (NULL);
	ft_strlcpy(total, s1, s1_len + 1);
	ft_strlcpy(&total[s1_len], s2, s2_len + 1);
	return (total);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen((char *)s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str)
			*str = '\0';
		return (str);
	}
	if (len > ft_strlen((char *)s))
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dstsize > i)
	{
		if (src[i] == '\0' || dstsize == i + 1)
		{
			dst [i] = '\0';
			break ;
		}
		else
			dst[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	str_size;

	str_size = ft_strlen(src) + 1;
	cpy = (char *)malloc(str_size * sizeof(char));
	if (cpy)
		ft_strlcpy(cpy, src, str_size);
	return (cpy);
}
