// PAL Week 11 - Examine a C Program - List ADT implementation
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-19		initial

#include "List.h"

LIST CreateList()
{
	LIST newList = { 0 }; // "safe" state for the list

	return newList;
}

bool AddItemToList(PLIST list, ITEM newItem)
{
	PNODE newNode = CreateNode(newItem);

	if (!newNode) // checks if the node was allocated (malloc can fail)
		return false;


	/*
	* 1 - List is empty, therefore there is no "next".  
	* 
	* 2 - Continue checking for next nodes until you find the first available spot
	*/

	if (list->head == NULL) // list is empty
	{
		list->head = newNode;
	}
	else
	{
		PNODE currentNode = list->head;

		// find the last node in the list
		while (GetNextNode(currentNode))
		{
			currentNode = GetNextNode(currentNode);
		}

		SetNextNode(currentNode, newNode);
	}

	return true;
}

void DisplayList(LIST list)
{
	if (list.head) // common pattern to check if the list is empty
	{
		PNODE current = list.head;
		while (current)
		{
			DisplayItem(GetNodeItem(current));
			current = GetNextNode(current);
		}
	}
	else
	{
		printf("List is empty. Add items to it!\n");
	}
}

void DisposeList(PLIST list)
{
	PNODE temp;
	PNODE currentNode = list->head;

	while (currentNode)
	{
		/* free what is behind me that way i don't let go of the chain */
		temp = currentNode;
		currentNode = GetNextNode(currentNode);
		DisposeNode(temp);
	}
}