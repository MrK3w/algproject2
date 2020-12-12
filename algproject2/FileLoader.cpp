#define _CRT_SECURE_NO_WARNINGS
#include "FileLoader.h"
FILE* file;
int number_of_nodes = 0;
int i = 0;
int* src;
int* dest;

void FileLoader::openFile()
{
	file = fopen("graf.txt", "r");
}

void FileLoader::closeFile()
{
	fclose(file);
}

int FileLoader::getRows()
{
	return i;
}
void FileLoader::SetNodes()
{
	fscanf(file, "%d", &number_of_nodes);
};

int FileLoader::GetNodes()
{
	return number_of_nodes;
}

int* FileLoader::Getsrc()
{
	return src;
}

int* FileLoader::Getdest()
{
	return dest;
}

void setEdges()
{
	src = new int[number_of_nodes]();
	dest = new int[number_of_nodes]();
	while ((fscanf(file, "%d %d\n", &src[i], &dest[i])) != EOF) i++;
}

void FileLoader::loadGraph()
{
	
	openFile();
	SetNodes();
	setEdges();
	closeFile();
}