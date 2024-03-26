// PAL Week 12 - Examine a C Program - Dynamic Memory Management (DMM)
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-27		initial

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
*
* malloc
*	- Allocates memory to a variable
*	- If there is no memory it will fail
*
* calloc
*	- Allocates blocks of memory
*		- Doesn't have to be initialized
*	- If there is no memory it will fail
*
* realloc
*	- Reallocates memory
*		- Expand or contract the area covered by a pointer
*	-  If there is no memory it will fail
* free
*	- Leaks can happen if you dont free memory
*
*/

int main(void)
{
	int* pInt = (int*)malloc(sizeof(int)); // dynamically allocating an integer
	if (!pInt) // error checking, remember from linked lists?
	{
		fprintf(stderr, "Error allocating pInt. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	printf("\n pInt:%d \n", *pInt); // what will this display? how can we fix it?

	int* pAnotherInt = (int*)malloc(5 * sizeof(int));
	if (!pAnotherInt)
	{
		fprintf(stderr, "Error allocating pAnotherInt. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("AnotherInt[%d] = %d\n", i, pAnotherInt[i]);
	}

	char* string = (char*)malloc(sizeof(char) * 6);
	if (!string)
	{
		fprintf(stderr, "Error allocating string. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	strcpy(string, "Omar\0");
	printf("\n initial string: %s \n", string);

	char* pString = string; // hold a copy just in case realloc fails!
	string = (char*)realloc(string, sizeof(char) * 20);
	if (!string)
	{
		free(pString); // free original!

		fprintf(stderr, "Error reallocating string. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	strcat(string, " Nunez Siri");
	printf("\n realloced string: %s \n", string); // Omar Nunez Siri

	printf("string: %p and pString: %p \n", string, pString);
	printf("string: %s and pString %s \n", string, pString);

	free(pInt);
	free(pAnotherInt);
	free(string);

	return 0;
}