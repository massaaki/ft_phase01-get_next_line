#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	const int READ_ONLY = 0;

	fd = open("test-file.txt", READ_ONLY);
	if (fd == -1)
	{	
		return 1;
	}

	get_next_line(fd);


	return (0);
}