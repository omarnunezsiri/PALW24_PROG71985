// PAL Week 5 - Program 3:
//					implement printCondorInformation function
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-04		initial
// 1.1			2023-09-28		reviewed

#include <stdio.h>

void printCondorInformation(char[], char[]);

#define MAX_STRING 20
int main(void)
{
	char name[MAX_STRING] = "onunezsiri";
	char id[MAX_STRING] = "8760878";

	printCondorInformation(name, id);
	return 0;
}

void printCondorInformation(char name[], char ID[])
{
	printf("Condor: %s%s\n", name, ID);
}