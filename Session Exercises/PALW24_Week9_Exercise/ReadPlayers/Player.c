#define _CRT_SECURE_NO_WARNINGS

#include "Player.h"
#include <stdio.h>
#include <stdlib.h>

// Read players from a stream (file)
// our formatted data is:
// id, integer
// username, string
// password, string
// experience, float

/*
* the common structure for File I/O
* FILE* create a stream
* 
* check if it opened
*	if it did, do what you wanna do
*	if it didn't, print an error message and exit
* close the file
*/

void ReadPlayersFromStream(PLAYER players[], int sizeOfArray, char* FILENAME)
{
	// creates a file pointer and attempts to open the file
	FILE* fp = fopen(FILENAME, "rb");

	// if the file pointer is not NULL, we can read the file
	if (fp)
	{
		for (int index = 0; index < sizeOfArray; index++) {

			// players[index] 0xAA
			// p 0xBB
			PLAYER* p = &players[index]; // get the current player as a pointer
			fscanf(fp, "%d", &p->id);
			fscanf(fp, "%s", p->username);
			fscanf(fp, "%s", p->password);
			fscanf(fp, "%f", &p->exp);

			SkyBlue();
			printf("Read player %d %s\n", p->id, p->username);
			Reset();
		}
	}
	else
	{
		fprintf(stderr, "Unable to open file %s. Exiting...\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	// don't forget to close the file :)
	fclose(fp);
}

// Display the collection of players to stdout
void DisplayPlayers(PLAYER players[], int sizeOfArray)
{
	for (int index = 0; index < sizeOfArray; index++) {
		
		// players[index] 0xAA
		// p 0xBB
		PLAYER p = players[index]; // get the current player as a pointer

		/* display that player */
		MintGreen();
		printf("\nPlayer ID: %d\n", p.id);
		printf("Username: %s\n", p.username);
		printf("Password: %s\n", p.password);
		printf("Experience: %.2f\n", p.exp);
		Reset();
	}
}
