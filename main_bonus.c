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

	int i;
	char *current_line1;
	char *current_line2;


	i = 0;
	file1 = fopen("./file-tests/str1", "r");
	file2 = fopen("./file-tests/str2", "r");


	current_line1 = get_next_line(file1->_file);

	current_line2 = get_next_line(file2->_file);

	current_line1 = get_next_line(file1->_file);
	// current_line1 = get_next_line(file1->_file);
	current_line2 = get_next_line(file2->_file);

	fclose(file1);
	fclose(file2);

}