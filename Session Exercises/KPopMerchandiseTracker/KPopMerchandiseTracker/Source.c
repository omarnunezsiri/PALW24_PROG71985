// PAL Project - K-Pop Merchandise Tracker
// 
// PROG71985-W24
// PAL Attendees
// 
// revision history
// 1.0			2024-03-11		initial version

#include <stdio.h>
#include <stdlib.h>

#include "MerchList.h"

int main(int argc, char* argv[])
{
	// accept the merchandise filename as a command-line arg
	if (argc != 2)
	{
		fprintf(stderr, "Usage %s <MerchDbFilename>", argv[0]);
		exit(EXIT_FAILURE);
	}

	char* fileName = argv[1];

	printf("-----------------------------------------------------\n");
	printf("|                                                   |\n");
	printf("|             K-Pop Merchandise Tracker             |\n");
	printf("|                                                   |\n");
	printf("-----------------------------------------------------\n\n");

	KMLIST myList = CreateList(); // create a list
	if(!StreamReadList(&myList, fileName)) // read from file
	{
		fprintf(stderr, "Error reading from file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	printf("----------------------- List after reading from file ---------------------\n");
	DisplayList(&myList); // display while being empty

	if (!StreamWriteList(&myList, fileName)) // write to file
	{
		fprintf(stderr, "Error writing to file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	DisposeList(&myList); // don't forget to free dynamically allocated variables!

	return 0;
} 