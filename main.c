#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

void testGnl(char *file_path, char *test_name);

int main(void)
{
	// testGnl("./file-tests/41_no_nl", "41_no_nl");
	testGnl("./file-tests/41_with_nl", "41_with_nl");
	// testGnl("./file-tests/42_no_nl", "42_no_nl");
	// testGnl("./file-tests/42_with_nl", "42_with_nl");
	// testGnl("./file-tests/43_no_nl", "43_no_nl");
	// testGnl("./file-tests/43_with_nl", "43_with_nl");
	// testGnl("./file-tests/alternate_line_nl_no_nl", "alternate_line_nl_no_nl");
	// testGnl("./file-tests/alternate_line_nl_with_nl", "alternate_line_nl_with_nl");
	// testGnl("./file-tests/random", "random");
	// testGnl("./file-tests/big_line_no_nl", "big_line_no_nl");
	// testGnl("./file-tests/big_line_with_nl", "big_line_with_nl");
	// testGnl("./file-tests/empty", "empty");
	// testGnl("./file-tests/multiple_line_no_nl", "multiple_line_no_nl");
	// testGnl("./file-tests/multiple_line_with_nl", "multiple_line_with_nl");
	// testGnl("./file-tests/multiple_nlx5", "multiple_nlx5");
	// testGnl("./file-tests/nl", "nl");
	return (0);
}

void testGnl(char *file_path, char *test_name)
{
	FILE *file;
	int i;
	char *current_line;

	/**
	 * Test #01 
	**/
	printf("----------------------------------------------------------\n");
	printf("-> TEST #01 - %s\n", test_name);					
	printf("----------------------------------------------------------\n");

	i = 0;
	file = fopen(file_path, "r");
	
	//use first line in linux
	// while ((current_line = get_next_line(file->_fileno)) != NULL)
	while ((current_line = get_next_line(file->_file)) != NULL)
	{
		printf("Line %i : '%s'\n", i, current_line);
		free(current_line);
		i++;
	}

	fclose(file);
	printf("\n");
	printf("\n");
}