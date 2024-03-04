// PAL Week 9 - Examine a C Program - writing an ADT to a file
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-05		initial

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 30
#define FILENAME "playerDB.txt"

typedef struct Player
{
	int id;
	char username[MAXSTR];
	char password[MAXSTR];
	float exp;
}PLAYER;

int main(void)
{
	PLAYER p1 = { .id = 1, .username = "player1", .password = "greatpassword", .exp = 12321.3513f };

	FILE* fp = fopen(FILENAME, "w"); // does FILENAME need to exist in our directory?

	if (fp) // what does this check for?
	{
		fprintf(fp, "%d\n", p1.id);
		fprintf(fp, "%s\n", p1.username);
		fprintf(fp, "%s\n", p1.password);
		fprintf(fp, "%f\n", p1.exp);

		printf("Wrote %zd bytes to %s.\n", sizeof(struct Player), FILENAME);
	}
	else
	{
		fprintf(stderr, "Unable to open %s. Exiting...\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	fclose(fp); // don't forget to close your files!
	return 0;
}