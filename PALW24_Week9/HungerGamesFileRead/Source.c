// PAL Week 9 - Examine a C Program - reading from a file character by character
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-05		initial

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "hungergames.txt"

int main(void)
{
	FILE* fp = fopen(FILENAME, "r"); // what would happen if we opened in "w" mode instead?
	int countChars = 0;

	if (fp)
	{
		char eachChar;
		while ((eachChar = fgetc(fp)) != EOF) // what is EOF? how is it useful here?
		{
			putc(eachChar, stdout);
			countChars++;
		}

		printf("\nRead %d characters from %s.\n", countChars, FILENAME);
	}
	else
	{
		fprintf(stderr, "Unable to open %s. Exiting...\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	fclose(fp); // don't forget to close your files!
	return 0;
}