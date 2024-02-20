// PAL Week 7 - User ADT implementation
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-20		initial
// 1.1			2023-10-14		reviewed/refactored
// 3.0			2024-02-17		removed file io

#include "User.h"
#include <string.h>

USER CreateUser(int id, char username[], char password[], char DOB[])
{
	USER user;

	user.id = id;

	/* What does _s mean? */
#ifdef _WIN32 // What is this preprocessor directive being used for?
	strcpy_s(user.username, MAXSTR, username);
	strcpy_s(user.password, MAXSTR, password);
	strcpy_s(user.DOB, MAXSTR, DOB);
#else
	strcpy(user.username, username);
	strcpy(user.password, password);
	strcpy(user.DOB, DOB);
#endif

	return user;
}

void DisplayUser(USER thisUser)
{
	printf("\nID: %d\n", thisUser.id);
	printf("Username: %s\n", thisUser.username);
	printf("Password: %s\n", thisUser.password);
	printf("DOB: %s\n", thisUser.DOB);
}






/* use as extra notes: */

void StreamWriteUser(USER thisUser, FILE* fp)
{
	/* Can we use fprintf to display a message to stdout? */
	fprintf(fp, "%d\n", thisUser.id);
	fprintf(fp, "%s\n", thisUser.username);
	fprintf(fp, "%s\n", thisUser.password);
	fprintf(fp, "%s\n", thisUser.DOB);
}

// Credits: PROG71985 Week 6 - Dr. Hendrikse
void removeTrailingNewLine(char* buffer)
{
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}

USER StreamReadUser(FILE* fp)
{
	int id;
	char username[MAXSTR];
	char password[MAXSTR];
	char DOB[MAXSTR];

	/* fcanf vs fgets? */
	fscanf_s(fp, "%d\n", &id);

	fgets(username, MAXSTR, fp); // no format

	fgets(password, MAXSTR, fp);

	fgets(DOB, MAXSTR, fp);

	removeTrailingNewLine(username);
	removeTrailingNewLine(password);
	removeTrailingNewLine(DOB);

	return CreateUser(id, username, password, DOB);
}