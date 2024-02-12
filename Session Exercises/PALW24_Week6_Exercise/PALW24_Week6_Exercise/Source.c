// PAL Week 6 - Exercise:
//					Write a C program that uses the hardcoded array of student names and takes their overall GPA from input.
//					The program then *should* display the names of the students with a GPA of 3.0 or higher.
// 
// 
// Challenge(s): 
//	- Prompt the user to enter the names of the students rather than hardcoding them
//	    - Kudos if the program allows me to enter full names with spaces
//  - Implement a FindOccurrences function. This takes the array of student names and a string query.
//      - It should return the number of occurrences of the query in the array
// 
// PROG71985W24
// Authors: PAL Attendees
// 
// 
// revision history:
// 1.0			2024-02-12		initial

#define MAX_FULL_NAME 50
#define MAX_STUDENTS 5
#define MIN_GPA 3.0

#include <stdio.h>
#include <string.h>

// Challenge #2: FindOccurrences implementation
int FindOccurrences(char names[][MAX_FULL_NAME], int arrayLength, const char* query)
{
	int occurrences = 0; // no occurrences at the beginning

	for (int index = 0; index < arrayLength; index++)
	{
		// haystack = the whole string
		// needle = what you're searching
		char* haystack = names[index];
		char* ret = strstr(haystack, query);

		if (ret != NULL) // found it
		{
			occurrences++;
		}
	}

	return occurrences;
}

// ANSI ESCAPE CHARACTERS (beautifying output)
void SkyBlue()
{
	printf("\x1b[38;5;153m"); // ANSI ESCAPE CHARACTER (Sky Blue)
}

void MintGreen()
{
	printf("\x1b[38;5;194m"); // ANSI ESCAPE CHARACTER (Mint Green)
}

void Reset()
{
	printf("\x1b[0m"); // ASNI ESCAPE CHARACTER (Reset)
}

int main() 
{
	// DO NOT MODIFY THIS CODE
	char studentNames[MAX_STUDENTS][MAX_FULL_NAME] = { "Omar Nunez\0", "Ema Anderson\0", "Valentina Jones\0", "Sophie Nunez\0", "George Fletcher\0" };
	
	// YOUR CODE GOES HERE

	// Challenge #2 (FindOccurrences usage)
	const char* query = "Nunez";

	SkyBlue();
	printf("Finding %s in studentNames...\n", query);
	int occurrences = FindOccurrences(studentNames, MAX_STUDENTS, query);
	printf("Found %d occurrences of %s\n", occurrences, query);
	Reset();

	// Prompt for each of the student's GPAs 
	float GPA[MAX_STUDENTS];

	//
	// 1. Declaration 
	// 2. Condition
	// 3. Increment/Decrement
	//
	for (int index = 0; index < MAX_STUDENTS; index++)
	{
		printf("%s, please enter your GPA:\n", studentNames[index]);
		scanf_s("%f", &GPA[index]);

		//printf("%s --> %f\n", studentNames[index], GPA[index]);
	}

	// Display back only the students that have a GPA of 3.0 or higher
	for (int index = 0; index < MAX_STUDENTS; index++)
	{
		if (GPA[index] >= MIN_GPA)
		{
			MintGreen();
			printf("Congrats %s!\n", studentNames[index]);
			Reset();
		}
	}

	return 0;
}