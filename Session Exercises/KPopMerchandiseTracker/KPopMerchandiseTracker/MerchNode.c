#include "MerchNode.h"
#include <stdio.h>
#include <stdlib.h>

PKMNODE CreateNode(KMERCH newMerch)
{
	PKMNODE newNode = (PKMNODE)malloc(sizeof(KMNODE)); // allocating memory
	if (!newNode) // check if memory was allocated
	{
		fprintf(stderr, "Error allocating new node. Exiting...\n");
		return NULL; // decoupling function from main implementation
	}

	newNode->merch = newMerch;
	newNode->next = NULL;

	return newNode;
}

PKMNODE GetNextNode(PKMNODE node)
{
	return node->next;
}

void SetNextNode(PKMNODE currentNode, PKMNODE nextNode)
{
	currentNode->next = nextNode;
}

KMERCH GetNodeKMerch(PKMNODE node)
{
	return node->merch;
}

void DisposeNode(PKMNODE node)
{
	free(node); // free heap allocated memory
}