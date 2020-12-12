#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

class FileLoader
{
public:
	void openFile();
	void closeFile();
	void SetNodes();
	int GetNodes();
	int* Getsrc();
	int* Getdest();
	int getRows();
	int getI();
	void loadGraph();
};


