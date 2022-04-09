/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/04/09 15:17:20 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	update_list(struct list **accumulator, int fd);
void	ft_join_accumulator(char **accumulator, char *current_buffer);
void	delete_fd(struct list **accumulator, int fd);
char	*ft_split_n(char **accumulator, char *ptr_n, int file_return);

char	*get_next_line(int fd)
{
	char				current_buffer[BUFFER_SIZE + 1];
	static struct list	*accumulator;
	struct list			*c;
	int					file_return;

	if (fd < 0)
		return (NULL);
	if (!accumulator)
	{
		accumulator = malloc(sizeof(struct list));
		accumulator->buf = malloc(sizeof(char));
		accumulator->buf[0] = '\0';
		accumulator->fd = fd;
		accumulator->next = NULL;
	}
	else
		update_list(&accumulator, fd);
	c = accumulator;
	while (c->fd != fd)
		c = c->next;
	file_return = BUFFER_SIZE;
	while (file_return > 0)
	{
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		if (file_return < 0)
		{
			free(c->buf);
			delete_fd(&accumulator, fd);
			return (NULL);
		}
		current_buffer[file_return] = '\0';
		ft_join_accumulator(&(c->buf), current_buffer);
		if (ft_strchr(c->buf, '\n'))
			return (ft_split_n(&c->buf, ft_strchr(c->buf, '\n'), file_return));
	}
	if (file_return == 0)
		if ((ft_strlen(c->buf) > 0))
			return (ft_split_n(&c->buf, ft_strchr(c->buf, '\n'), file_return));

	free(c->buf);
	delete_fd(&accumulator, fd);
	return (NULL);
}

void	delete_fd(struct list **accumulator, int fd)
{
	struct list		*to_exclude;
	struct list		*previous;

	to_exclude = *accumulator;
	while (to_exclude->fd != fd)
	{
		previous = to_exclude;
		to_exclude = to_exclude->next;
	}
	if ((*accumulator)->fd == fd)
		(*accumulator) = to_exclude->next;
	else
		previous = to_exclude->next;
	free(to_exclude);
}

void	update_list(struct list **accumulator, int fd)
{
	struct list	*current;
	struct list	*new;
	int			found;

	current = (*accumulator);
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
		new = malloc(sizeof(struct list));
		new->buf = malloc(sizeof(char));
		new->buf[0] = '\0';
		new->fd = fd;
		new->next = (*accumulator);
		(*accumulator) = new;
	}
}

/*
 * This funciton receive the accumulator
 * and current_buffer
 * Then gets the correcty length
 * Finally realloc and copy correcty to avoid leaks
 */
void	ft_join_accumulator(char **accumulator, char *current_buffer)
{
	char	*tmp_acc;

	if (ft_strlen(current_buffer) == 0)
		return ;
	tmp_acc = ft_strjoin(*accumulator, current_buffer);
	free(*accumulator);
	*accumulator = malloc(ft_strlen(tmp_acc) * sizeof(char) + 1);
	ft_strlcpy(*accumulator, tmp_acc, ft_strlen(tmp_acc) + 1);
	free(tmp_acc);
}

/*
* return line and update accumulator
*/
char	*ft_split_n(char **accumulator, char *ptr_n, int file_return)
{
	int		length;
	char	*line;
	char	*rest;

	if (file_return == 0 && !ft_strchr(*accumulator, '\n'))
	{
		line = malloc(ft_strlen(*accumulator) * sizeof(char) + 1);
		ft_strlcpy(line, *accumulator, ft_strlen(*accumulator) + 1);
		free(*accumulator);
		*accumulator = malloc(sizeof(char));
		*accumulator[0] = '\0';
		return (line);
	}
	length = ptr_n - *accumulator + 1;
	line = malloc(length * sizeof(char) + 1);
	rest = malloc(ft_strlen(ptr_n) * sizeof(char));
	ft_strlcpy(line, *accumulator, length + 1);
	ft_strlcpy(rest, (ptr_n + 1), ft_strlen(ptr_n));
	free(*accumulator);
	*accumulator = malloc(ft_strlen(rest) * sizeof(char) + 1);
	ft_strlcpy(*accumulator, rest, ft_strlen(rest) + 1);
	free(rest);
	return (line);
}
