// PAL Week 11 - Examine a C Program - Node ADT implementation
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-19		initial

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

PNODE CreateNode(ITEM newItem)
{
	PNODE newNode = (PNODE)malloc(sizeof(NODE)); // allocating memory
	if (!newNode) // check if memory was allocated
	{
		fprintf(stderr, "Error allocating new node. Exiting...\n");
		return NULL; // decoupling function from main implementation
	}

	newNode->item = newItem;
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

ITEM GetNodeItem(PNODE node)
{
	return node->item;
}

void DisposeNode(PNODE node)
{
	DisposeItem(&node->item);
	free(node); // why is this important?
}