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

	// get the information then display (refactor to use a display function for merch)
	char* name = getMerchName(&kmerch);
	char* type = getMerchType(&kmerch);
	char* idol = getMerchIdolGroup(&kmerch);
	float price = getMerchPrice(&kmerch);
	bool owned = getMerchOwnership(&kmerch);

	// change the format of the kpop merch's ownership to be more user-friendly
	char* friendlyOwnership = owned ? "YES" : "NO";

	// display the information
	printf("%s, a %s for the fans of %s, only for $%.2fCAD! (OWNED? %s)\n", name,
																			type,
																			idol,
																			price,
																			friendlyOwnership);
}