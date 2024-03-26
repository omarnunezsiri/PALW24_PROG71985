#include "MerchList.h"
#include <string.h>

KMLIST CreateList()
{
	KMLIST newList = { 0 }; // initialize all fields to 0

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

void DisplayList(PKMLIST list)
{
	if (list->head) // common pattern to check if the list is empty
	{
		PKMNODE current = list->head;
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

bool StreamWriteList(PKMLIST list, char* filename)
{
	if (list->head) // common pattern to check if the list is empty
	{
		FILE* stream = fopen(filename, "w");

		if (!stream)
		{
			fprintf(stderr, "Error opening file %s\n", filename);
			return false;
		}

		PKMNODE current = list->head;
		while (current)
		{
			KMERCH currentMerch = GetNodeKMerch(current);
			writeMerchToFile(&currentMerch, stream);
			current = GetNextNode(current);
		}
	}
	else
	{
		fprintf(stderr, "List is empty. Add items to it!\n");
	}

	return true;
}

bool StreamReadList(PKMLIST newList, char* filename)
{
	FILE* stream = fopen(filename, "r");

	// check if the file was opened
	if (!stream)
	{
		fprintf(stderr, "Error opening file %s\n", filename);
		return false;
	}

	// continue reading until the end of the file
	int c;
	KMERCH merch;
	while ((c = fgetc(stream)) != EOF)
	{
		readMerchFromFile(stream, &merch);
		if (!AddKMerchToList(newList, merch)) // verify that the merch was added to the list
		{
			fprintf(stderr, "Error adding merch to list\n");
			return false;
		}
	}

	fclose(stream); // dont forget to close the file
	return true;
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