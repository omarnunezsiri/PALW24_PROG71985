#include "MerchList.h"

KMLIST CreateList()
{
	KMLIST newList = { 0 }; // "safe" state for the list

	return newList;
}

bool AddKMerchToList(PKMLIST list, KMERCH merch)
{
	PKMNODE newNode = CreateNode(merch);

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
		PKMNODE currentNode = list->head;

		// find the last node in the list
		while (GetNextNode(currentNode))
		{
			currentNode = GetNextNode(currentNode);
		}

		SetNextNode(currentNode, newNode);
	}

	return true;
}

void DisplayList(KMLIST list)
{
	if (list.head) // common pattern to check if the list is empty
	{
		PKMNODE current = list.head;
		while (current)
		{
			KMERCH currentMerch = GetNodeKMerch(current);
			displayMerchInformation(&currentMerch);
			current = GetNextNode(current);
		}
	}
	else
	{
		printf("List is empty. Add items to it!\n");
	}
}

void DisposeList(PKMLIST list)
{
	PKMNODE temp;
	PKMNODE currentNode = list->head;

	while (currentNode)
	{
		/* free what is behind me that way i don't let go of the chain */
		temp = currentNode;
		currentNode = GetNextNode(currentNode);
		DisposeNode(temp);
	}
}