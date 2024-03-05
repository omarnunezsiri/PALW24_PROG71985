// PAL Week 9 - Write a C Program - Write a collection of Datas to a file
// 
// PROG71985-W24
// Madison
//
// revision history
// 1.0			2024-03-05		initial version

#define MAX_DATAS 5
#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

int main() 
{
	DATA datas[MAX_DATAS] = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 } };

	if (writeData(datas, MAX_DATAS, "data.bin") == true)
	{
		printf("Data written to file.\n");
	}
	else
	{
		//fprintf(stderr, "Unable to write data to file.\nExiting...\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
