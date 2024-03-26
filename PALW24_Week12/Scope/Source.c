// PAL Week 12 - Examine a C Program - Scope demo
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-27		initial

#include <stdio.h>
#include <Windows.h> // Sleep() functionality for demo
const int x = 100; // what scope does x cover?

int DivideTwoNumbers(int*);

int main(void)
{
	int y = 9; // what scope does y cover?

	printf("%d / %d: %d\n", x, y, DivideTwoNumbers(&y));
	Sleep(10000);

	// what scope does i cover?
	for (int i = 0; i < 500; i++) {
		if (i % 2 == 0)
			printf("Counter!");
	}

	//printf("%d", i); // what will happen here?

	return 0;
}

// what scope does this y cover?
int DivideTwoNumbers(int* y)
{
	(*y)++; // are we updating y in line 9 as well?

	return (x / *y);
}