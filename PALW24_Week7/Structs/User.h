// PAL Week 7 - User ADT header
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-20		initial
// 2.0			2023-10-14		refactored
// 3.0			2024-02-17		removed file io

#pragma once
#include <stdio.h>

#define MAXSTR 30

// review: what is typedef?
typedef struct User
{
	int id;
	char username[MAXSTR];
	char password[MAXSTR];
	char DOB[MAXSTR];
}USER;

USER CreateUser(int, char[], char[], char[]); // creating a user
void DisplayUser(USER); // displaying a user

// extra notes 
void StreamWriteUser(USER, FILE*); // writing a user to a file
void removeTrailingNewLine(char*); // removing '\n'
USER StreamReadUser(FILE*); // reading a user from a file