// PAL Project - K-Pop Merchandise ADT implementation
// 
// PROG71985-W24
// Madison
// 
// revision history
// 1.0			2024-03-11		initial version
#define _CRT_SECURE_NO_WARNINGS

#define MERCH_STR_OWNED "YES"

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

// helper function to remove the trailing newline from a c-string
void removeTrailingNewLine(char* str)
{
	int length = strlen(str); 

	for (int i = 0; i < length; i++)
	{
		if (str[i] == '\n')
			str[i] = '\0';
	}
}

// setters (trust, but verify)
void setMerchName(PKMERCH merch, char* name) {	
	size_t nameLength = strlen(name); // get the length of the name

	if (name != NULL && nameLength >= 0 && nameLength <= MAX_NAME) 
	{
		removeTrailingNewLine(name);
		strncpy(merch->name, name, MAX_NAME);
	}
}

void setMerchType(PKMERCH merch, char* type) {
	
	size_t typeLength = strlen(type); // get the length of the type

	if (type != NULL && typeLength >= 0 && typeLength <= MAX_TYPE)
	{
		removeTrailingNewLine(type);
		strncpy(merch->type, type, MAX_TYPE);
	}
}

void setMerchIdolGroup(PKMERCH merch, char* idol) {
	
	size_t idolLength = strlen(idol); // get the length of the idol

	if (idol != NULL && idolLength >= 0 && idolLength <= MAX_IDOL)
	{
		removeTrailingNewLine(idol);
		strncpy(merch->idol, idol, MAX_IDOL);
	}
}

void setMerchPrice(PKMERCH merch, float price) {

	if(price >= 0) 
	{
		merch->price = price;
	}
}

void setMerchOwnership(PKMERCH merch, bool ownership) 
{
	merch->owned = ownership;
}

// getters
char* getMerchName(PKMERCH merch)
{
	return (merch->name);
}

char* getMerchType(PKMERCH merch) 
{
	return (merch->type);
}

char* getMerchIdolGroup(PKMERCH merch) 
{
	return (merch->idol);
}

float getMerchPrice(PKMERCH merch) 
{
	return (merch->price);
}

bool getMerchOwnership(PKMERCH merch) 
{
	return (merch->owned);
}

// display
void displayMerchInformation(PKMERCH merch)
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
void writeMerchToFile(PKMERCH merch, FILE* fp) 
{
	if (fp)
	{
		char* friendlyOwnership = merch->owned ? "YES" : "NO"; // friendly representation

		fprintf(fp, "\n%s\n", merch->name);
		fprintf(fp, "%s\n", merch->type);
		fprintf(fp, "%s\n", merch->idol);
		fprintf(fp, "$%0.2f\n", merch->price);
		fprintf(fp, "%s\n", friendlyOwnership);

		//printf("Wrote %zd bytes to to file\n", sizeof(struct Merchandise));
	}
	else
	{
		fprintf(stderr, "fp is null in writeMerchToFile. Avoiding any actions!\n");
	}
}

void readMerchFromFile(FILE* fp, PKMERCH merch)
{
	if (fp)
	{
		char temp[MAX_NAME]; // temporary buffer for reading from file
		float tempF; // temporary float for reading from file

		// read the merchandise information from the file

		fgets(temp, MAX_NAME, fp);
		removeTrailingNewLine(temp);
		setMerchName(merch, temp);

		fgets(temp, MAX_TYPE, fp);
		removeTrailingNewLine(temp);
		setMerchType(merch, temp);

		fgets(temp, MAX_IDOL, fp);
		setMerchIdolGroup(merch, temp);

		fscanf_s(fp, "$%f\n", &tempF);
		setMerchPrice(merch, tempF);

		fgets(temp, sizeof(MERCH_STR_OWNED) + 1, fp);
		setMerchOwnership(merch, strcmp(temp, MERCH_STR_OWNED) == 0);
	}
	else
	{
		fprintf(stderr, "fp is null in readMerchFromFile. Avoiding any actions!\n");
	}
}