/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/04/11 15:12:14 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_split_n(char **accumulator, int last_line);
int		ft_join_accumulator(char **accumulator, int fd);
void	ft_keep_rest_accumulator(char **accumulator, int len, int i);
int		ft_manage_split(char **accumulator, char **current, int file_return);

char	*get_next_line(int fd)
{
	static char		*accumulator;
	char			*current_line;
	int				file_return;

	if (!accumulator)
		accumulator = ft_strdup("");
	file_return = 1;
	while (file_return > 0 || ft_strchr(accumulator, '\n'))
	{
		file_return = ft_join_accumulator(&accumulator, fd);
		if (file_return < 0)
			return (NULL);
		if (ft_manage_split(&accumulator, &current_line, file_return) == 1)
			return (current_line);
	}
	return ((free(accumulator)), (accumulator = NULL), NULL);
}

/*
 * Receive accumulator and if is last line or not
 * returns current_line and update accumulator with rest
 */
char	*ft_split_n(char **accumulator, int last_line)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*accumulator);
	while ((ft_strlen(*accumulator) != 0) && (*(*accumulator + i) != '\0'))
	{
		if ((*accumulator)[i] == '\n')
		{
			line = malloc(i * sizeof(char) + 2);
			ft_strlcpy(line, *accumulator, i + 2);
			break ;
		}
		else if (last_line == 1)
		{
			line = malloc(len * sizeof(char) + 1);
			ft_strlcpy(line, *accumulator, len + 1);
			free(*accumulator);
			*accumulator = ft_strdup("");
		}
		i++;
	}
	ft_keep_rest_accumulator(accumulator, len, i);
	return (line);
}

/*
 * This funciton receive the accumulator
 * and current_buffer
 * Then gets the correcty length
 * Finally realloc and copy correcty to avoid leaks
 */
int	ft_join_accumulator(char **accumulator, int fd)
{
	char	*tmp_acc;
	char	*current_buffer;
	int		file_return;

	current_buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	file_return = read(fd, current_buffer, BUFFER_SIZE);
	if (file_return < 0)
	{
		if (*accumulator != NULL)
		{
			free(*accumulator);
			*accumulator = NULL;
		}
		return (free(current_buffer), file_return);
	}
	current_buffer[file_return] = '\0';
	tmp_acc = ft_strjoin(*accumulator, current_buffer);
	free(*accumulator);
	free(current_buffer);
	*accumulator = malloc(ft_strlen(tmp_acc) * sizeof(char) + 1);
	ft_strlcpy(*accumulator, tmp_acc, ft_strlen(tmp_acc) + 1);
	free(tmp_acc);
	return (file_return);
}

/*
 * Remove content before \n and realoc the rest in accumulator
 */
void	ft_keep_rest_accumulator(char **accumulator, int len, int i)
{
	char	*temp_accumulator;

	if (ft_strlen(*accumulator) == 0)
		return ;
	temp_accumulator = malloc((len - i) * sizeof(char));
	ft_strlcpy(temp_accumulator, *(accumulator) + i + 1, (len - i));
	free(*accumulator);
	*accumulator = malloc((len - i) * sizeof(char));
	ft_strlcpy(*accumulator, temp_accumulator, ft_strlen(temp_accumulator) + 1);
	free(temp_accumulator);
}

/*
 * Manage split to call when is the eof or not
 */
int	ft_manage_split(char **accumulator, char **line, int file_return)
{
	char	*ptr_n;

	ptr_n = ft_strchr(*accumulator, '\n');
	if (ptr_n)
	{
		*line = ft_split_n(accumulator, 0);
		return (1);
	}
	else if ((file_return == 0 && ft_strlen(*accumulator) > 0))
	{
		*line = ft_split_n(accumulator, 1);
		return (1);
	}
	return (0);
}
