// PAL
//					beautifying output with ANSI escape characters
// 
// PROG71985W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include "Color.h"

// ANSI ESCAPE CHARACTERS (beautifying output)
void SkyBlue()
{
	printf("\x1b[38;5;153m"); // ANSI ESCAPE CHARACTER (Sky Blue)
}

void MintGreen()
{
	printf("\x1b[38;5;194m"); // ANSI ESCAPE CHARACTER (Mint Green)
}

void Reset()
{
	printf("\x1b[0m"); // ASNI ESCAPE CHARACTER (Reset)
}