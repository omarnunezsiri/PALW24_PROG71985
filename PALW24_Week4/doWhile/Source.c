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
#include <stdbool.h> // exists in C++, not included in C

void main(void)
{
	const int BOOT_UP = 123192; // AUTH Protocol Key dedicated to this client
	const int BOOT_UP2 = 10000; // Addition of a second Protocol Key for double auth
	int key;
	int anotherKey;
	bool isConnected = false; // why set it before the loop and not inside? 

	printf("Hello Client! Validation to connect to the server is required.\n");
	do
	{
		printf("Please enter the boot_up AUTH keys to establish connection with the server: ");
		int symbols_returned = scanf("%d %d", &key, &anotherKey);

		// printf("symbols_returned %d\n", symbols_returned);

		// we have to check if the scanf returns the correct number of items assigned (2 in this case)
		if (symbols_returned != 2)
		{
			printf("Invalid input. Only two integers are allowed!\n");
			while ((getchar()) != '\n'); // clears input buffer
		}
		else if (key == BOOT_UP && anotherKey == BOOT_UP2)
			isConnected = true;
		else
			printf("That's not correct!\n");
	} while (isConnected == false);

	printf("\nServer says: Welcome Back!\n");
}