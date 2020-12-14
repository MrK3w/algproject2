#include "Eccentricity.h"
#include <iostream>
#include <list>
#include "FileLoader.h"
int numberOfNodes = 0;
std::vector<int>* graph;

void Eccentricity::findGraphCenter()
{
	FileLoader file;
	//read file
	file.loadGraph();
	numberOfNodes = file.getNodes();
	setGraph(file);
	int* eccentricityPoints = new int[numberOfNodes]();
	eccentricityPoints = getEccentricity(graph);
	findCenter(eccentricityPoints);
	delete[] eccentricityPoints;
}

void Eccentricity::setGraph(FileLoader File)
{
	graph = new std::vector<int>[numberOfNodes];
	//set src and dest edges
	int* src = new int[numberOfNodes]();
	int* dest = new int[numberOfNodes]();
	src = File.getSrc();
	dest = File.getDest();
	int rows = File.getRows();
	int j = 0;
	while (j != rows)
	{
		addEdge(graph, src[j], dest[j]);
		j++;
	}
}

void Eccentricity::addEdge(std::vector<int> graph[], int src, int dest)
{
	graph[src].push_back(dest);
	graph[dest].push_back(src);
}
bool Eccentricity::BFS(std::vector<int> graph[], int src, int dest,int pred[], int dist[])
{
	// a queue to maintain queue of vertices whose
	// adjacency list is to be scanned as per normal
	// DFS algorithm
	std::list<int> queue;
	// boolean array visited[] which stores the
	// information whether ith vertex is reached
	// at least once in the Breadth first search
	bool* visited = new bool[numberOfNodes];
	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	for (int i = 0; i < numberOfNodes; i++)
	{
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}
	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);
	// standard BFS algorithm
	while (!queue.empty())
	{
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < graph[u].size(); i++)
		{
			if (visited[graph[u][i]] == false)
			{
				visited[graph[u][i]] = true;
				dist[graph[u][i]] = dist[u] + 1;
				pred[graph[u][i]] = u;
				queue.push_back(graph[u][i]);
				// We stop BFS when we find
				// destination.
				if (graph[u][i] == dest) return true;
				}
			}
		}
	return false;
}

// utility function to calculate the shortest distance
// between two vertex
int Eccentricity::getDistance(std::vector<int> graph[], int start, int dest)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from start
	int* pred = new int[numberOfNodes];
	int* dist = new int[numberOfNodes];
	if (BFS(graph, start, dest, pred, dist) == false)
	{
		return 0;
	}
	// vector path stores the shortest path
	std::vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1)
	{
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	return dist[dest];
}

int Eccentricity::largestDistance(int arr[], int n)
{
	// Initialize maximum element 
	int max = arr[0];
	// Traverse array elements  
	// from second and compare 
	// every element with current max  
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;	
}
//finding the centre of the graph from eccentricity points
void Eccentricity::findCenter(int* eccentricityPoints)
{
	std::vector<int> centerPoints;
	//lowest index of array eccentricitPoints setted
	int tmp = eccentricityPoints[0];
	for (int i = 1; i < numberOfNodes; i++)
	{
		//if lower value was found clear vector and save new value
		if (tmp > eccentricityPoints[i])
		{
			tmp = eccentricityPoints[i];
			centerPoints.clear();
			centerPoints.push_back(i);
			continue;
		}
		//if same value was found push there another value
		if (tmp == eccentricityPoints[i]) centerPoints.push_back(i);
	}
	//write out Centrer points
	std::cout << "Center points of graph are: ";
	for (int i = 0; i < centerPoints.size(); i++) std::cout << centerPoints.at(i) << ' ';
	}

//get eccentricity points from all paths between nodes
int* Eccentricity::getEccentricity(std::vector<int> graph[])
{
	int* eccentricityPoints = new int[numberOfNodes]();
	//find path to every node from one node and find longest path then save it
	for (int i = 0; i < numberOfNodes; i++)
	{
		int* array = new int[numberOfNodes];
		for (int j = 0; j < numberOfNodes; j++)
		{
			array[j] = getDistance(graph, i, j);
		}
		eccentricityPoints[i] = largestDistance(array, numberOfNodes);
		delete[] array;
	}
	return eccentricityPoints;
}