// PAL Project - K-Pop Merchandise Tracker
// 
// PROG71985-W24
// PAL Attendees
// 
// revision history
// 1.0			2024-03-11		initial version

#include <stdio.h>
#include <stdlib.h>

#include "Merchandise.h"

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

	KMERCH kmerch; // uninitialized merchandise

	// use setters for safety
	setMerchName(&kmerch, "BTS Love Yourself Sweatshirt");
	setMerchType(&kmerch, "Sweatshirt");
	setMerchIdolGroup(&kmerch, "BTS");
	setMerchPrice(&kmerch, 33.77f);
	setMerchOwnership(&kmerch, false); // not owned yet :(

	// simplify the process using a function
	displayMerchInformation(&kmerch);

	// write the merch to a file
	FILE* fp = fopen(fileName, "w");

	if (fp != NULL) // null checking 
	{
		writeMerchToFile(&kmerch, fp);
		fclose(fp); // don't forget to close your files!
	}
	else
	{
		fprintf(stderr, "Unable to open %s. Exiting...\n", fileName);
		exit(EXIT_FAILURE);
	}
} 