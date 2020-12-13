#pragma once
#include <vector>

class FileLoader;

class Eccentricity
{
public: void findGraphCenter();
private:bool BFS(std::vector<int> adj[], int src, int dest, int pred[], int dist[], int numberOfNodes);
	   int getDistance(std::vector<int> graph[], int start, int dest, int number_of_nodes);
	   int largestDistance(int arr[], int n);
	   void findCenter(int* eccentricityPoints, int numberOfNodes);
	   int* getEccentricity(std::vector<int> graph[], int number_of_nodes);
	   void addEdge(std::vector<int> adj[], int src, int dest);
	   std::vector<int>* setGraph(FileLoader file);
};

