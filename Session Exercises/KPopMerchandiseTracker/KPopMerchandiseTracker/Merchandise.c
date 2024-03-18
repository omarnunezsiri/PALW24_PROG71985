// PAL Project - K-Pop Merchandise ADT implementation
// 
// PROG71985-W24
// Madison
// 
// revision history
// 1.0			2024-03-11		initial version
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "Merchandise.h"

KMERCH CreateMerch(char* name, char* type, char* idol, float price, bool owned)
{
	KMERCH merch;

	setMerchName(&merch, name);
	setMerchType(&merch, type);
	setMerchIdolGroup(&merch, idol);
	setMerchPrice(&merch, price);
	setMerchOwnership(&merch, owned);

	return merch;
}

// setters (trust, but verify)
void setMerchName(KMERCH* merch, char* name) {	
	size_t nameLength = strlen(name); // get the length of the name

	if (name != NULL && nameLength >= 0 && nameLength <= MAX_NAME) 
	{
		strncpy(merch->name, name, MAX_NAME);
	}
}

void setMerchType(KMERCH* merch, char* type) {
	
	size_t typeLength = strlen(type); // get the length of the type

	if (type != NULL && typeLength >= 0 && typeLength <= MAX_TYPE)
	{
		strncpy(merch->type, type, MAX_TYPE);
	}
}

void setMerchIdolGroup(KMERCH* merch, char* idol) {
	
	size_t idolLength = strlen(idol); // get the length of the idol

	if (idol != NULL && idolLength >= 0 && idolLength <= MAX_IDOL)
	{
		strncpy(merch->idol, idol, MAX_IDOL);
	}
}

void setMerchPrice(KMERCH* merch, float price) {

	if(price >= 0) 
	{
		merch->price = price;
	}
}

void setMerchOwnership(KMERCH* merch, bool ownership) 
{
	merch->owned = ownership;
}

// getters
char* getMerchName(KMERCH* merch)
{
	return (merch->name);
}

char* getMerchType(KMERCH* merch) 
{
	return (merch->type);
}

char* getMerchIdolGroup(KMERCH* merch) 
{
	return (merch->idol);
}

float getMerchPrice(KMERCH* merch) 
{
	return (merch->price);
}

bool getMerchOwnership(KMERCH* merch) 
{
	return (merch->owned);
}

// display
void displayMerchInformation(KMERCH* merch)
{
	// change the format of the kpop merch's ownership to be more user-friendly
	char* friendlyOwnership = merch->owned ? "YES" : "NO";

	// display the information
	printf("%s, a %s for the fans of %s, only for $%.2fCAD! (OWNED? %s)\n", merch->name,
																			merch->type,
																			merch->idol,
																			merch->price,
																			friendlyOwnership);
}

// file i/o
void writeMerchToFile(KMERCH* merch, FILE* fp) 
{
	if (fp)
	{
		char* friendlyOwnership = merch->owned ? "YES" : "NO"; // friendly representation

		fprintf(fp, "%s\n", merch->name);
		fprintf(fp, "%s\n", merch->type);
		fprintf(fp, "%s\n", merch->idol);
		fprintf(fp, "$%0.2f\n", merch->price);
		fprintf(fp, "%s\n", friendlyOwnership);

		printf("Wrote %zd bytes to to file\n", sizeof(struct Merchandise));
	}
	else
	{
		fprintf(stderr, "fp is null in writeMerchToFile. Exiting...\n");
		exit(EXIT_FAILURE);
	}
}