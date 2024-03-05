#include "Data.h"
#include <stdlib.h>

//false = 0 (bad)
//true = 1 (good)

bool writeData(DATA data[], int sizeOfArray, char* FILENAME)
{
	FILE* fp = fopen(FILENAME, "wb"); //open or create a file in write binary mode

	if(fp != NULL) {	//this is what if(fp) checks for

		fwrite(data, sizeof(DATA), sizeOfArray, fp); //write the array to the file in binary mode
		//fclose(fp);

		//FILE* anotherfp = fopen(FILENAME, "rb"); //open the file in read binary mode
		//DATA* tempData = (DATA*)malloc(sizeof(DATA) * sizeOfArray); //allocate memory for a single DATA struct

		//if (tempData)
		//{
		//	fread(tempData, sizeof(DATA), sizeOfArray, anotherfp); //read the file into the tempData array
		//	for (int i = 0; i < sizeOfArray; i++)
		//	{
		//		printf("Key: %d, size %zd\n", tempData[i].key, tempData[i].sizeKey); 
		//	}
		//	free(tempData); //free the memory allocated for tempData
		//} 
		//else
		//{
		//	fprintf(stderr, "Unable to allocate memory for tempData.\nExiting...\n");
		//	return false;
		//}
	} 
	else
	{
		fprintf(stderr, "Unable to open %s.\nExiting...\n", FILENAME);
		return false;
	}

	fclose(fp); //NEVER FORGET TO CLOSE FILES :D
	return true;
}