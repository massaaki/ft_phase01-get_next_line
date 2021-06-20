#include "get_next_line.h"

/*
** Description:
** Function which a new line read a file descriptor
** 
** Parameters:
** fd: File descriptor
** **line: value to read
**
** Returns:
** 1: if a line has been read
** 0: EOF reached
** -1: Error
*/

int	get_next_line(int fd, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*current_line;

	current_line = NULL;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	


	
	return (0);
}
