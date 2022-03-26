#include "get_next_line.h"

#include <stdio.h>

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int file_return;

	// If successful, the number of bytes actually read is returned
	// EOF, returns 0
	// Fail, returns -1

	/*
	 * file_return = read(fd, buffer, BUFFER_SIZE);
	 * if EOF retuns 0, we can put read in a while loop
	 */

	while ((file_return = read(fd, buffer, BUFFER_SIZE)) > 0) 
	{
		//if entered here, means that we have more buffer
		buffer[file_return] = '\0'; // ensure end of string
		printf("BUFF: %s\n", buffer);



		char *rest_after = ft_strchr(buffer, '\n');
		if(rest_after != NULL) {
			rest_after = rest_after + 1;
		}
		printf("rest_after : %s\n", rest_after);

		printf("*******************\n");
	}

		
	return NULL;
}
