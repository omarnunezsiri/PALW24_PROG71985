// PAL Week 7 - Cord ADT implementation
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-20		initial
// 2.0			2023-10-14		refactored
// 3.0			2024-02-17		removed file io

#define _CRT_SECURE_NO_WARNINGS

#include "Cord.h"
#include "Color.h"
#include <stdlib.h>

CORD CreateCord(int id)
{
	CORD cord;

	cord.id = id;
	cord.currentIndex = 0;

	return cord;
}

void DisplayCord(CORD thisCord)
{
	SkyBlue();
	printf("CORD id: %d\n", thisCord.id);
	printf("countUsers (currentIndex): %d\n", thisCord.currentIndex);

	MintGreen();
	printf("\nUsers:\n");

	Reset();
	for (int i = 0; i < thisCord.currentIndex; i++)
	{
		DisplayUser(thisCord.users[i]);
	}
}


// Pass by Reference/Value review
void AddNewUser(CORD* thisCord, USER newUser)
{
	thisCord->users[thisCord->currentIndex] = newUser;
	thisCord->currentIndex++;
}







/* use as extra notes: */

void StreamWriteCord(CORD thisCord, char filename[])
{
	FILE* fp = fopen(filename, "w"); // what does "w" mean?
	if (!fp) // file doesn't exist or is corrupted
	{
		fprintf(stderr, "Error opening %s. Exiting...\n", filename);
		exit(1);
	}
	else
	{
		fprintf(fp, "%d\n", thisCord.id);
		fprintf(fp, "%d\n", thisCord.currentIndex);

		for (int i = 0; i < thisCord.currentIndex; i++) // looping through the collection of users
		{
			StreamWriteUser(thisCord.users[i], fp);
		}

		fclose(fp); // don't forget to close your files!
	}
}

void StreamReadCord(CORD* newCord, char filename[])
{
	FILE* fp = fopen(filename, "r"); // what does "r" mean?
	if (!fp)
	{
		fprintf(stderr, "Error opening %s. Exiting...\n", filename);
		exit(1);
	}
	else
	{
		int id;
		int currentIndex;
		fscanf_s(fp, "%d\n", &id); // read the Cord's id
		*newCord = CreateCord(id);

		fscanf_s(fp, "%d\n", &currentIndex); // read the number of users

		/* Read all users */
		for (int i = 0; i < currentIndex; i++)
		{
			USER newUser = StreamReadUser(fp);
			AddNewUser(newCord, newUser);
		}

		fclose(fp); // don't forget to close your files!
	}
}