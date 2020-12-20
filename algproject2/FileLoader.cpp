#define _CRT_SECURE_NO_WARNINGS
#include "FileLoader.h"
#include <iostream>
#include <string>

FILE* file;
int nodes = 0;
int rows = 0;
int* src;
int* dest;

//method for opening file
void FileLoader::openFile()
{
	file = fopen("graf4.txt", "r");
	if(file == NULL)
	{
		std::cout << "File cannot be loaded";
		exit(1);
	}
}
//method for closing file
void FileLoader::closeFile()
{
	fclose(file);
}

//method which returns row in file - first row
int FileLoader::getRows()
{
	return rows;
}
//read first number in file which is number of nodes in graph
void FileLoader::setNodes()
{
	fscanf(file, "%d", &nodes);
};
//return number of nodes
int FileLoader::getNodes()
{
	return nodes;
}

void FileLoader::setRows()
{
	char c;
	for (c = getc(file); c != EOF; c = getc(file))
		if (c == '\n') // Increment count if this character is newline 
			rows++;
}
//get source nodes
int* FileLoader::getSrc()
{
	return src;
}
//get destination nodes
int* FileLoader::getDest()
{
	return dest;
}
//define size of src and dest
void FileLoader::defineEdges()
{
	src = new int[rows]();
	dest = new int[rows]();
}
//set edges 
void FileLoader::setEdges()
{
	defineEdges();
	int i = 0;
	int poc = 0;
	int pom = 0;
	while ((fscanf(file, "%d %d\n", &src[i], &dest[i])) != EOF) i++;
	if (src[0] != 0)
	{
		pom = src[0];
		while (pom != 0)
		{
			pom--;
			poc++;
		}

		fclose(file);
		FILE* fptr = fopen("graf4.txt", "w");
		fprintf(fptr, "%d\n", dest[i - 1] - poc + 1);
		for (int k = 0; k < rows-1; k++)
		{
			fprintf(fptr, "%d %d\n", src[k] - poc, dest[k] - poc);
		}
		fclose(file);
		loadGraph();
	}
}
//method for opening file setting everything needed and then close file 
void FileLoader::loadGraph()
{
	openFile();
	setRows();
	rewind(file);
	setNodes();
	setEdges();
	closeFile();
}