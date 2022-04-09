#include "get_next_line_bonus.h"

#include <stdio.h>
#include <stdlib.h>

void testBonus(void);

int main(void)
{

	testBonus();
	
	return (0);
}

void testBonus(void)
{
	FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;

	char *current_line;

	file1 = fopen("./file-tests/41_with_nl", "r");
	file2 = fopen("./file-tests/42_with_nl", "r");
	file3 = fopen("./file-tests/43_with_nl", "r");
	file4 = fopen("./file-tests/nl", "r");

	// while ((current_line1 = get_next_line(file1->_file)) != NULL)
	// {
	// 	printf("Line %i : '%s'\n", i, current_line1);
	// 	free(current_line1);
	// 	i++;
	// }

	/*
		fd[0] = open("files/41_with_nl", O_RDWR);
		1 - gnl(1000, NULL);
		2 - gnl(fd[0], "0123456789012345678901234567890123456789\n");
	*/

	current_line = get_next_line(1000); // NULL
	printf("current_line: '%s'\n", current_line);
	free(current_line);
	printf("- - - - - - - - - \n");

	current_line = get_next_line(file1->_file); //0123456789012345678901234567890123456789\n
	printf("current_line: %s\n", current_line);
	free(current_line);
	printf("- - - - - - - - - \n");

	/*
		fd[1] = open("files/42_with_nl", O_RDWR);
		1 - gnl(1001, NULL);
		2 - gnl(fd[1], "01234567890123456789012345678901234567890\n");
	*/
	current_line = get_next_line(1001);
	printf("current_line: '%s'\n", current_line);
	free(current_line);
	printf("- - - - - - - - - \n");

	current_line = get_next_line(file2->_file);
	printf("current_line: '%s'\n", current_line);
	free(current_line);
	printf("- - - - - - - - - \n");

	// current_line = get_next_line(1002);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file3->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(1003);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file1->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);


	// current_line = get_next_line(1004);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file2->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(1005);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file3->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file1->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file2->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file3->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);


	//--
	// current_line = get_next_line(1006);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file4->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(1007);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	// current_line = get_next_line(file4->_file);
	// printf("current_line: '%s'\n", current_line);
	// free(current_line);

	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);

}