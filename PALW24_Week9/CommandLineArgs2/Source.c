// PAL Week 9 - Examine a C Program - command line arguments to display a range of numbers
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-05		initial

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Command line arguments not set properly. Exiting...\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("The first-first argument is %s\n", argv[0]);
		printf("The first argument is %s\n", argv[1]);
		printf("The second argument is %s\n", argv[2]);
	}
	
	// research! what is atoi?
	int loopStart = atoi(argv[1]);
	int loopEnd = atoi(argv[2]);

	// assuming we don't want to start or end at 0
	if (loopStart == 0 || loopEnd == 0)
	{
		fprintf(stderr, "Invalid arguments. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	printf("\nThe loop will start at %d and end at %d\n\n", loopStart, loopEnd);

	for (int i = loopStart; i <= loopEnd; i++)
	{
		printf("%d ", i);
	}

	return 0;
}