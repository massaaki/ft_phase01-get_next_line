/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:55:57 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/15 12:05:16 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*	find the first ocurrency of 'c' and returns
*	a pointer of str found or null
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = 0;
	while (*(ptr_s + i))
	{
		if (*(ptr_s + i) == (char)c)
			return (ptr_s + i);
		i++;
	}
	if (c == '\0')
		return (ptr_s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL)
		return ((size_t) NULL);
	if (dstsize < 1)
		return (ft_strlen(src));
	i = 0;
	while (*(src + i) && (i < dstsize - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

/**
 * char * strdup(const char *s1);
 * allocates sufficient memory for a copy of the string s1
 * return a pointer to it
 * Dependences: ft_strlen, ft_strlcpy
 **/
char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

/**
 * ft_strjoin
 * join str1 and str2
 **/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;
	size_t	total_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc((total_size) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(dest + j + i) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}
