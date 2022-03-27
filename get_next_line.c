/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/03/27 16:18:27 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			file_return;
	static char	*rest;
	char		*current_line;

	if (!rest)
		rest = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	current_line = ft_strdup(rest);
	file_return = BUFFER_SIZE;
	while (file_return > 0)
	{
		file_return = read(fd, buffer, BUFFER_SIZE);
		buffer[file_return] = '\0';
	}
	return (NULL);
}
