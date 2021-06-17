#include <stdio.h>
#include <string.h> //temporary
#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
int get_next_line(int fd, char **line)
{
	char buffer[100 + 1];

	read(fd, &buffer, 100);
	buffer[100] = '\0';
	*line = strdup(buffer);

	return (0);
}

int	main(void)
{
	char	*line;
	int fd;

	fd = open("sample.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
