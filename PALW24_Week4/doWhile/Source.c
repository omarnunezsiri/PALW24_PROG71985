// PAL Week 4 - Program 2:
//					use of do...while loop to for client/server validation
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-28		initial
// 1.1			2023-09-21		reviewed

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void main(void)
{
	const int BOOT_UP = 123192; // AUTH Protocol Key dedicated to this client
	int key;
	bool isConnected = false; // why set it before the loop and not inside?

	printf("Hello Client! Validation to connect to the server is required.\n");
	do
	{
		printf("Please enter the boot_up AUTH key to establish connection with the server: ");
		scanf("%d", &key); // assumes that the input is okay (can you fix it?)

		if (key == BOOT_UP)
			isConnected = true;
		else
			printf("That's not correct!\n");
	} while (isConnected == false);

	printf("\nServer says: Welcome Back!\n");
}