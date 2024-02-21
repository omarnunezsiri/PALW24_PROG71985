// PAL Week 7 - Topping ADT implementation
// 
// PROG71985-F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-10-15		initial

#include "Topping.h"
#include <string.h>

TOPPING CreateTopping(int id, char* toppingName)
{
	TOPPING Topping;

	Topping.id = id;

	/* What does _s mean? */
#ifdef _WIN32 // Preprocessor directives
	strcpy_s(Topping.name, MAXSTR, toppingName);
#else
	strcpy(Topping.name, toppingName);
#endif

	return Topping;
}

void DisplayTopping(TOPPING thisTopping)
{
	printf("ID: %d\n", thisTopping.id);
	printf("Topping name: %s\n", thisTopping.name);
}

void StreamWriteTopping(TOPPING thisTopping, FILE* fp)
{
	/* Can we use fprintf to display a message to stdout? */
	fprintf(fp, "%d\n", thisTopping.id);
	fprintf(fp, "%s\n", thisTopping.name);
}

// Credits: PROG71985 Week 6 - Dr. Hendrikse
void removeTrailingNewLine(char* buffer)
{
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0'; // strings are null (\0) terminated
}

TOPPING StreamReadTopping(FILE* fp)
{
	int id;
	char Toppingname[MAXSTR];

	/* fcanf vs fgets? */
	fscanf_s(fp, "%d\n", &id); // takes a format

	fgets(Toppingname, MAXSTR, fp); // no format

	/* What do we need removeTrailingNewLine for? */
	removeTrailingNewLine(Toppingname);

	return CreateTopping(id, Toppingname);
}