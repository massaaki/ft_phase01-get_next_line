#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file;
	int i;
	char *current_line;

	i = 0;
	file = fopen("./test-file2.txt", "r");

	while ((current_line = get_next_line(file->_file)) != NULL)
	{
		printf("Line %i : %s\n", i, current_line);
		i++;
	}

	fclose(file);

	return (0);
}