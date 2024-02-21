// PAL Week 7 - Topping ADT header
// 
// PROG71985-F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-10-15		initial

#pragma once
#include <stdio.h>

#define MAXSTR 30
typedef struct Topping
{
	int id;
	char name[MAXSTR];
}TOPPING;

TOPPING CreateTopping(int, char*); // creating a topping
void DisplayTopping(TOPPING); // displaying a topping
void StreamWriteTopping(TOPPING, FILE*); // writing a topping to a file
void removeTrailingNewLine(char*); // removing '\n'
TOPPING StreamReadTopping(FILE*); // reading a topping from a file