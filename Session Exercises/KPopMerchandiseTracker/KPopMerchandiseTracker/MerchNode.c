#include "MerchNode.h"
#include <stdio.h>
#include <stdlib.h>

PNODE CreateNode(KMERCH newMerch)
{
	PNODE newNode = (PNODE)malloc(sizeof(NODE)); // allocating memory
	if (!newNode) // check if memory was allocated
	{
		fprintf(stderr, "Error allocating new node. Exiting...\n");
		return NULL; // decoupling function from main implementation
	}

	newNode->merch = newMerch;
	newNode->next = NULL;

	return newNode;
}

PNODE GetNextNode(PNODE node)
{
	return node->next;
}

void SetNextNode(PNODE currentNode, PNODE nextNode)
{
	currentNode->next = nextNode;
}

KMERCH GetNodeKMerch(PNODE node)
{
	return node->merch;
}

void DisposeNode(PNODE node)
{
	free(node); // free heap allocated memory
}