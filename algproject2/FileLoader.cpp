#define _CRT_SECURE_NO_WARNINGS
#include "FileLoader.h"
#include <iostream>
#include <string>

FILE* file;
int numberOfNodes = 0;
int rows = 0;
int* src;
int* dest;
//method for opening file
void FileLoader::openFile()
{
	file = fopen("1.txt", "r");
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
void FileLoader::SetNodes()
{
	fscanf(file, "%d", &numberOfNodes);
};
//return number of nodes
int FileLoader::getNodes()
{
	return numberOfNodes;
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
	src = new int[numberOfNodes]();
	dest = new int[numberOfNodes]();
}
//set edges 
void FileLoader::setEdges()
{
	defineEdges();
	while ((fscanf(file, "%d %d\n", &src[rows], &dest[rows])) != EOF) rows++;
}
//method for opening file setting everything needed and then close file 
void FileLoader::loadGraph()
{
	openFile();
	SetNodes();
	setEdges();
	closeFile();
}