// PAL Week 9 - Examine a C Program - reading a Data ADT from a file
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-05		initial

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "dataDB.txt"
typedef struct Data
{
	size_t sizeKey;
	int key;
}DATA;

int main(void)
{
	FILE* fp = fopen(FILENAME, "r"); // what happens if FILENAME doesn't exist in our directory?

	if (fp)
	{
		size_t sizeTemp;
		int keyTemp;
		
		fscanf_s(fp, "%zd", &sizeTemp);
		fscanf_s(fp, "%d", &keyTemp);

		DATA newData = { sizeTemp, keyTemp };
		printf("%zd --- %d\n", newData.sizeKey, newData.key);
	}
	else
	{
		fprintf(stderr, "Unable to open %s. Exiting...\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	fclose(fp);
	return 0;
}