/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/03/30 20:35:51 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_split_n(char **accumulator, int last_line);

char *get_next_line(int fd)
{
	char			current_buffer[BUFFER_SIZE + 1];
	int				file_return;
	static char		*accumulator;
	char			*current_line;
	char			*ptr_n;

	if (!accumulator) 
		accumulator = ft_strdup("");

	file_return = BUFFER_SIZE;
	while (file_return > 0)
	{
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		current_buffer[file_return] = '\0';

		if (file_return > 0 || ft_strchr(accumulator, '\n'))
		{
			// printf("alocou\n"); //Esta entrando 2x no loop
			accumulator = ft_strjoin(accumulator, current_buffer);
					ptr_n = ft_strchr(accumulator, '\n');
			if (ptr_n)
			{
				current_line = ft_split_n(&accumulator, 0);
				return (current_line);
			}
		}
		else if ((file_return == 0 && ft_strlen(accumulator) > 0))
		{
			ptr_n = ft_strchr(accumulator, '\n');
			current_line = ft_split_n(&accumulator, 1);
			return (current_line);
		}
	}
	free(accumulator);
	accumulator = NULL;
	return (NULL);
}

char	*ft_split_n(char **accumulator, int last_line)
{
	char	*line;
	int		len;
	char	*temp_accumulator;
	int		i;

	i = 0;
	len = ft_strlen(*accumulator);
	while (*(*accumulator + i) != '\0')
	{
		if (*(*accumulator + i) == '\n')
		{
			line = malloc(i * sizeof(char) + 1 + 1);
			ft_strlcpy(line, *accumulator, i + 1 + 1);
			break;
		}
		else if (last_line == 1)
		{
			line = malloc(ft_strlen(*accumulator) * sizeof(char) + 1);
			ft_strlcpy(line, *accumulator, ft_strlen(*accumulator) + 1);
			*accumulator = malloc(1);
		}
		i++;
	}
	temp_accumulator = malloc((len - i) * sizeof(char));
	ft_strlcpy(temp_accumulator, *(accumulator) + i + 1, (len - i + 1));
	*accumulator = malloc(len - i * sizeof(char));
	ft_strlcpy(*accumulator, temp_accumulator, ft_strlen(temp_accumulator) + 1);
	free(temp_accumulator);
	return (line);
}
