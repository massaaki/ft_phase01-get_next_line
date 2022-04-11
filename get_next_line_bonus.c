/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/04/11 16:14:30 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char					*current_buffer;
	static struct s_list	*accumulator;
	struct s_list			*c;
	int						file_return;

	c = ft_initialize(&accumulator, fd, &file_return);
	if (c == NULL)
		return (NULL);
	while (file_return > 0)
	{
		current_buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		if (file_return < 0)
		{
			free(c->buf);
			free(current_buffer);
			return ((delete_fd(&accumulator, fd)), NULL);
		}
		current_buffer[file_return] = '\0';
		ft_join_accumulator(&(c->buf), current_buffer);
		free(current_buffer);
		if (ft_strchr(c->buf, '\n'))
			return (ft_split_n(&c->buf, ft_strchr(c->buf, '\n'), file_return));
	}
	if ((file_return == 0) && (ft_strlen(c->buf) > 0))
		return (ft_split_n(&c->buf, ft_strchr(c->buf, '\n'), file_return));
	free(c->buf);
	return (delete_fd(&accumulator, fd), NULL);
}

void	delete_fd(struct s_list **acc, int fd)
{
	struct s_list	*to_exclude;
	struct s_list	*previous;

	to_exclude = *acc;
	while (to_exclude->fd != fd)
	{
		previous = to_exclude;
		to_exclude = to_exclude->next;
	}
	if ((*acc)->fd == fd)
		(*acc) = to_exclude->next;
	else
		previous = to_exclude->next;
	free(to_exclude);
}

void	update_list(struct s_list **acc, int fd)
{
	struct s_list	*current;
	struct s_list	*new;
	int				found;

	current = (*acc);
	found = 0;
	while ((current != NULL ))
	{
		if (fd == current->fd)
		{
			found = 1;
			break ;
		}
		current = current->next;
	}
	if (found == 0)
	{
		new = malloc(sizeof(struct s_list));
		new->buf = malloc(sizeof(char));
		new->buf[0] = '\0';
		new->fd = fd;
		new->next = (*acc);
		(*acc) = new;
	}
}

/*
 * This funciton receive the accumulator
 * and current_buffer
 * Then gets the correcty length
 * Finally realloc and copy correcty to avoid leaks
 */
void	ft_join_accumulator(char **acc, char *current_buffer)
{
	char	*tmp_acc;

	if (ft_strlen(current_buffer) == 0)
		return ;
	tmp_acc = ft_strjoin(*acc, current_buffer);
	free(*acc);
	*acc = malloc(ft_strlen(tmp_acc) * sizeof(char) + 1);
	ft_strlcpy(*acc, tmp_acc, ft_strlen(tmp_acc) + 1);
	free(tmp_acc);
}

/*
* return line and update accumulator
*/
char	*ft_split_n(char **acc, char *ptr_n, int file_return)
{
	int		length;
	char	*line;
	char	*rest;

	if (file_return == 0 && !ft_strchr(*acc, '\n'))
	{
		line = malloc(ft_strlen(*acc) * sizeof(char) + 1);
		ft_strlcpy(line, *acc, ft_strlen(*acc) + 1);
		free(*acc);
		*acc = malloc(sizeof(char));
		*acc[0] = '\0';
		return (line);
	}
	length = ptr_n - *acc + 1;
	line = malloc(length * sizeof(char) + 1);
	rest = malloc(ft_strlen(ptr_n) * sizeof(char));
	ft_strlcpy(line, *acc, length + 1);
	ft_strlcpy(rest, (ptr_n + 1), ft_strlen(ptr_n));
	free(*acc);
	*acc = malloc(ft_strlen(rest) * sizeof(char) + 1);
	ft_strlcpy(*acc, rest, ft_strlen(rest) + 1);
	free(rest);
	return (line);
}
