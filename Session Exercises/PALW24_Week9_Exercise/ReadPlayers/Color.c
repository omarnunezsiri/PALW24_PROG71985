// PAL
//					beautifying output with ANSI escape characters
// 
// PROG71985W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include "Color.h"

// ANSI ESCAPE CHARACTER (Sky Blue)
void SkyBlue()
{
	printf("\x1b[38;5;153m"); 
}

// ANSI ESCAPE CHARACTER (Mint Green)
void MintGreen()
{
	printf("\x1b[38;5;194m"); 
}

// ASNI ESCAPE CHARACTER (Reset)
void Reset()
{
	printf("\x1b[0m"); 
}