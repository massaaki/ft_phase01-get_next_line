/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:55:57 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/15 12:05:20 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
* Initialize list of FDs, create if necessary and return the 
* address of current fd
*/
struct s_list	*ft_initialize(struct s_list **acc, int fd, int *file_return)
{
	struct s_list	*c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(*acc))
	{
		(*acc) = malloc(sizeof(struct s_list));
		(*acc)->buf = malloc(sizeof(char));
		(*acc)->buf[0] = '\0';
		(*acc)->fd = fd;
		(*acc)->next = NULL;
	}
	else
		update_list(acc, fd);
	c = *acc;
	while (c->fd != fd)
		c = c->next;
	*file_return = BUFFER_SIZE;
	return (c);
}

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
