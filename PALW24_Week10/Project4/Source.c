// PAL Week 10 - Examine a C Program - Reviewing pointers (pass by reference)
// 
// PROG71985-W23/W24
// 
// revision history
// 1.0			2023-03-13		initial
// 2.0			2024-03-09		refactored

#include <stdio.h>

int Add(int* x, int y)
{
	printf("address of x in add: %p\n", x);

	*x = 30; // are we changing the value of x in main?
	return (*x + y);
}

int main(void)
{
	int x = 10;
	int y = 20;

	printf("x before Add: %d\n", x);
	printf("address of x in main: %p\n", &x);

	int result = Add(&x, y);

	// will this display the updated value of x?
	printf("result = %d\n", result);
	printf("x after Add: %d\n", x);
}