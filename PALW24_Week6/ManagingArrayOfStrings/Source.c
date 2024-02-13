// PAL Week 6 - Program 4:
//					use an array of strings
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include <stdio.h>
#include "Color.h" // library for ANSI escape characters (beautifying output)

#define MAXARR 10

int main(void)
{
	// hard code the names
	char* names[MAXARR] = { "Omar", "Elijah", "Jeannie", "Dwain", "Reed", "Derick", "Martin", "Nunez", "Siri", "Wade" };

	SkyBlue();
	printf("The names, character by character are...\n");
	Reset();

	// an array of strings is a 2D array
	// review: whats a string in C?
	for (int i = 0; i < MAXARR; i++)
	{
		for (int j = 0; names[i][j] != '\0'; j++)
		{
			printf("%c", names[i][j]);
		}
		printf("\n");
	}

	return 0;
}