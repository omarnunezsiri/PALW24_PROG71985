// PAL Week 11 - Examine a C Program - Item ADT implementation
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-19		initial

#include "Item.h"

ITEM CreateItem(short int id)
{
	ITEM item = { id };

	return item;
}

void DisplayItem(ITEM item)
{
	printf("Item id: %hu\n", item.id);
}

void DisposeItem(PITEM item)
{
	// no free!
}