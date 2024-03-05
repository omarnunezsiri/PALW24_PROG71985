#pragma once
#include <stdbool.h>
#include <stdio.h>

#ifndef WRITE_DATA_H
#define WRITE_DATA_H

typedef struct Data
{
	size_t sizeKey;
	int key;
}DATA;

bool writeData(DATA*, int, char*);

#endif //WRITE_DATA_H