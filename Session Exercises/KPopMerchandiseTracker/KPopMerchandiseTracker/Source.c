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

	KMERCH kmerch = CreateMerch("BTS Love Yourself Sweatshirt", "Sweatshirt", "BTS", 33.77f, false);
	KMERCH kmerch2 = CreateMerch("Example 2", "Sweatshirt", "Black Pink", 34.5f, true);
	KMERCH kmerch3 = CreateMerch("Example 3", "Sweatshirt", "BTS", 35.1f, false);
	KMERCH kmerch4 = CreateMerch("Example 4", "Sweatshirt", "Red Velvet", 16.63f, true);

	LIST myList = CreateList();

	printf("----------------------- Empty List ---------------------\n");
	DisplayList(myList); // display while being empty

	printf("\n----------------------- Adding Items ---------------------\n");
	if (!AddKMerchToList(&myList, kmerch))
		exit(EXIT_FAILURE);

	if (!AddKMerchToList(&myList, kmerch2))
		exit(EXIT_FAILURE);

	if (!AddKMerchToList(&myList, kmerch3))
		exit(EXIT_FAILURE);

	if (!AddKMerchToList(&myList, kmerch4))
		exit(EXIT_FAILURE);

	printf("\n----------------------- Items ---------------------\n");
	DisplayList(myList); // display with items

	DisposeList(&myList); // don't forget to free dynamically allocated variables!

	return 0;
} 






	//// write the merch to a file
	//FILE* fp = fopen(fileName, "w");

	//if (fp != NULL) // null checking 
	//{
	//	writeMerchToFile(&kmerch, fp);
	//	fclose(fp); // don't forget to close your files!
	//}
	//else
	//{
	//	fprintf(stderr, "Unable to open %s. Exiting...\n", fileName);
	//	exit(EXIT_FAILURE);
	//}