// PAL Week 11 - Examine a C Program - Reviewing Linked Lists (adding and displaying items)
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-19		initial

#define FILENAME "myItems.dat"

#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Color.h"

int main(void)
{
	ITEM item = CreateItem(1);
	ITEM item2 = CreateItem(2);
	ITEM item3 = CreateItem(3);
	ITEM item4 = CreateItem(4);

	//LIST myList = StreamReadList(FILENAME);
	LIST myList = CreateList();

	cyan();
	printf("----------------------- Empty List ---------------------\n");
	DisplayList(myList); // display while being empty

	yellow();
	printf("\n----------------------- Adding Items ---------------------\n");
	if (!AddItemToList(&myList, item))
		exit(EXIT_FAILURE);

	if (!AddItemToList(&myList, item2))
		exit(EXIT_FAILURE);

	if (!AddItemToList(&myList, item3))
		exit(EXIT_FAILURE);

	if (!AddItemToList(&myList, item4))
		exit(EXIT_FAILURE);

	green();
	printf("\n----------------------- Items ---------------------\n");
	DisplayList(myList); // display with items
	reset();

	StreamWriteList(myList, FILENAME); // save changes to file
	DisposeList(&myList); // don't forget to free dynamically allocated variables!
	return 0;
}