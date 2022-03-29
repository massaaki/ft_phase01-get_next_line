/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:12 by massaaki          #+#    #+#             */
/*   Updated: 2022/03/28 17:28:12 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

char *split_line(char *start, char *end);


char *get_next_line(int fd)
{
	char			*current_buffer;
	int				file_return;
	static char		*accumulator;
	char 			*current_line;
	char 			*ptr_n;
	int length;

	if (!accumulator)
		accumulator = ft_strdup("");

	current_buffer = malloc((BUFFER_SIZE + 1) * sizeof(current_buffer));

	file_return = BUFFER_SIZE;
	while(file_return > 0) {
		// EOF retuns 0
		file_return = read(fd, current_buffer, BUFFER_SIZE);

		// Verify if file_return is eof(zero)
		if(file_return > 0)
		{

			accumulator = ft_strjoin(accumulator, current_buffer);

			ptr_n = ft_strchr(accumulator, '-');
			printf("accumultor: %s\n", accumulator);
			if (ptr_n)
			{
				printf("achou %s\n", ptr_n);
				// 	// Found'\n'
				// 	// printf("ACC: %s\n", accumulator);
				// 	printf("ptr_n: %s\n", ptr_n);
				current_line = split_line(accumulator, ptr_n);
				printf("line: %s\n", current_line);

				// 	printf("ACC: %s\n", accumulator);
				// 	// printf("ptr_n: %s\n", ptr_n);
				// 	printf("***********************\n");
				// 	if ((ft_strlen(ptr_n) - 1) > 0)
				// 	{
				// 		//tem resto

				// 		length = ft_strlen(ptr_n);
				// 		printf("TEM RESTO %s\n", ptr_n);
				// 	}
				// 	else
				// 	{
				// 		free(accumulator);
				// 		accumulator = ft_strdup("");
				// 	}

				// 	//update accumulator

				// 	return current_line;
			}

			// printf("current_buffer: %s\n", current_buffer);
			// printf("accumulator: %s\n", accumulator);
			// printf("ptr_n: %s\n", ptr_n);
			// printf("***********************\n");
		}
	}


	return (NULL);
}

// return line1 and rest
char * split_line(char *start, char *end)
{
	char *line;
	char *rest;
	int length;
	int i;

	*end = '\0';
	length = ft_strlen(start);
	*end = '-';

	line = malloc((length + 1) * sizeof(line));
	i = 0;
	while (i < length)
	{
		line[i] = *start;
		// *start = 'Z';
		start++;
		i++;
	}
	start++;
	line[i] = '\0';
	
	// printf("START %s\n", start);
	// rest = ft_strdup(start);
	// ft_strlcpy(rest, start, length+1);
	// printf("rest %s\n", rest);
	// printf("***********************\n");
	return line;
}
// return line1 and rest
