#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

class LoadFile
{
private:

	void add_edge(std::vector<int> adj[], int src, int dest);
public:
	void openFile();
	void closeFile();
	void SetNodes();
	int GetNodes();
	std::vector<int>* loadGraph();
};


