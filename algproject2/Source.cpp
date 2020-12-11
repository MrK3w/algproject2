#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Eccentricity.h"

using namespace std;

static void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}


class LoadFile
{
private:
	FILE* file;
	int number_of_nodes = 0;

public:
	void openFile()
	{
		file = fopen("graf.txt", "r");
	}

	void closeFile()
	{
		fclose(file);
	}

	void SetNodes()
	{
		fscanf(file, "%d", &number_of_nodes);
	};

	int GetNodes()
	{
		return number_of_nodes;
	}

	vector<int>* loadGraph()
	{
		int src, dest;
		openFile();
		SetNodes();
		vector<int>* graph = new vector<int>[number_of_nodes];
		while ((fscanf(file, "%d %d\n", &src, &dest)) != EOF) Eccentricity:add_edge(graph, src, dest);
		closeFile();
		return graph;
	}
};


int main()
{
	Eccentricity e1;
	e1.FindGraphCenter();
}
