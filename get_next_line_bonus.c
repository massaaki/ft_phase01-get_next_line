/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/04/08 21:58:54 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#define LETTER '\n'

void update_list(struct list **accumulator, int fd);
void ft_join_accumulator(char **accumulator, char *current_buffer);
void delete_fd(struct list **accumulator, int fd);
char *ft_split_n(char **accumulator, char *ptr_n, int file_return);

char *get_next_line(int fd)
{
	char				current_buffer[BUFFER_SIZE + 1];
	static struct list	*accumulator;
	struct list 		*current;
	int file_return;

	// printf("- - - - - \n");

	if(fd < 0)
		return (NULL);

	if (!accumulator)
	{
		accumulator = malloc(sizeof(struct list));
		accumulator->buffer = malloc(sizeof(char));
		accumulator->buffer[0] = '\0';
		accumulator->fd = fd;
		accumulator->next = NULL;
		// printf("start FD: %d\n", fd);
	}
	else
		update_list(&accumulator, fd);
	current = accumulator;

	while(current->fd != fd)
		current = current->next;
	

	file_return = BUFFER_SIZE;
	while (file_return > 0)
	{
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		current_buffer[file_return] = '\0';
		
		ft_join_accumulator(&(current->buffer), current_buffer);

		if (ft_strchr(current->buffer, LETTER)){
			// printf("buffer: '%s'\n", current_buffer);
			return ft_split_n(&current->buffer, ft_strchr(current->buffer, LETTER), file_return);
		}
	}
	

	if(file_return == 0)
	{
		
		if ((ft_strlen(current->buffer) > 0))
			return ft_split_n(&current->buffer, ft_strchr(current->buffer, LETTER), file_return);
		
	}
	free(current->buffer);
	delete_fd(&accumulator, fd);
	// printf("accumulator: '%s'\n", current->buffer);
	return (NULL);
}

void delete_fd(struct list **accumulator, int fd)
{
	struct list *to_exclude, *previous;

	to_exclude = *accumulator;
	while (to_exclude->fd != fd)
	{
		previous = to_exclude;
		to_exclude = to_exclude->next;
	}

	if ((*accumulator)->fd == fd) //begining
		(*accumulator) = to_exclude->next;
	else
		previous = to_exclude->next;
		
	free(to_exclude);
	// to_exclude->buffer = NULL;
}

void update_list(struct list **accumulator, int fd)
{
	struct list *current;
	struct list *new;
	int found;

	current = (*accumulator);
	found = 0;
	while ((current != NULL ))
	{
		if (fd == current->fd) {
			// printf("found FD: %d\n", fd);
			found = 1;
			break;
		}
		current = current->next;
	}
	if (found == 0)
	{
		// printf("new FD: %d\n", fd);
		new = malloc(sizeof(struct list));
		new->buffer = malloc(sizeof(char));
		new->buffer[0] = '\0';
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
void ft_join_accumulator(char **accumulator, char *current_buffer)
{
	char *tmp_acc;

	if (ft_strlen(current_buffer) == 0)
	{
		return;
	}
	tmp_acc = ft_strjoin(*accumulator, current_buffer);
	// printf("tmp_acc: '%s' alocado(%ld)\n", tmp_acc, (ft_strlen(tmp_acc) * sizeof(char) + 1));

	free(*accumulator);
	*accumulator = malloc(ft_strlen(tmp_acc) * sizeof(char) + 1);
	ft_strlcpy(*accumulator, tmp_acc, ft_strlen(tmp_acc) + 1);
	free(tmp_acc);
}

/*
* return line and update accumulator
*/
char *ft_split_n(char **accumulator, char *ptr_n, int file_return)
{
	int length;
	char *line;
	char *rest;

	if (file_return == 0 && !ft_strchr(*accumulator, LETTER))
	{
		line = malloc(ft_strlen(*accumulator) * sizeof(char) + 1);
		ft_strlcpy(line, *accumulator, ft_strlen(*accumulator) + 1);
		free(*accumulator);
		*accumulator = malloc(sizeof(char));
		*accumulator[0] = '\0';
		// printf("updated buffer: '%s'\n", *accumulator);
		return (line);
	}

	

	length = ptr_n - *accumulator + 1;
	// printf("-> '%s' [%ld]\n", ptr_n+1, ft_strlen(ptr_n));
	line = malloc(length * sizeof(char) + 1);
	rest = malloc(ft_strlen(ptr_n) * sizeof(char));
	
	ft_strlcpy(line, *accumulator, length + 1);
	ft_strlcpy(rest, (ptr_n + 1), ft_strlen(ptr_n));
	free(*accumulator);


	*accumulator = malloc(ft_strlen(rest) * sizeof(char) + 1);
	ft_strlcpy(*accumulator, rest, ft_strlen(rest) + 1);
	free(rest);

	// printf("updated buffer: '%s'\n", *accumulator);
	return (line);
}