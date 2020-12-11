#include "LoadFile.h"
FILE* file;
int number_of_nodes = 0;
void LoadFile::add_edge(std::vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
void LoadFile::openFile()
{
	file = fopen("graf.txt", "r");
}

void LoadFile::closeFile()
{
	fclose(file);
}

void LoadFile::SetNodes()
{
	fscanf(file, "%d", &number_of_nodes);
};

int LoadFile::GetNodes()
{
	return number_of_nodes;
}

std::vector<int>* LoadFile::loadGraph()
{
	int src, dest;
	openFile();
	SetNodes();
	std::vector<int>* graph = new std::vector<int>[number_of_nodes];
	while ((fscanf(file, "%d %d\n", &src, &dest)) != EOF) add_edge(graph, src, dest);
	closeFile();
	return graph;
}