// PAL Week 4 - Program 5:
//					use of control flow statements (if, else if, else) with a menu
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-28		initial
// 1.1			2023-09-25		reviewed

#include <stdio.h>

void main(void)
{
	printf("MENU\n");
	printf("a) Connect to MySQL Database\n");
	printf("b) Enter SSP Auth Key\n");
	printf("c) Import .AXX or .CHA file\n");
	printf("Please enter your option: ");

	char option = getchar();

	// how else can we implement the following?
	if (option == 'a')
		printf("MySQL Root Form\n");
	else if (option == 'b')
		printf("SSP Auth Key Form\n");
	else if (option == 'c')
		printf("Import pop-up\n");
	else
		printf("Only a-c.\n");

	return 0;
}