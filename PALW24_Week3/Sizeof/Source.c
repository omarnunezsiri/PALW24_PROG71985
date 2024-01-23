// PAL Week 3 - Program 4:
//					use of sizeof
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-21		initial

#include <stdio.h>

int main(void)
{
	int a = 70;
	float b = 15.0f;
	char c = 'a';
	double d = 20.0;

	printf("size in bytes for an integer: %d\n", sizeof(a));
	printf("size in bytes for a float: %d\n", sizeof(b));
	printf("size in bytes for a character: %d\n", sizeof(c));
	printf("size in bytes for a double: %d\n", sizeof(d));
	return 0;
}