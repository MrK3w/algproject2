#pragma once
#include <vector>

class FileLoader;
///Class <code>Eccenticity</code> is used for finding the center of the graph.
class Eccentricity
{
public:
///main drive function
void findGraphCenter();
	
private:
/// function to form edge between two vertices source and dest
/// a modified version of BFS that stores predecessor of each vertex in array graph and its distance from source in array
///@param Graph[] Array Graph for storing my graph
///@param src  src edge
///@param dest destination edge
///@param pred[] Array pred edge
///@param dist[] Array for distance edge
///@returns true if dest was found otherwise false
///@note Inspired by GeeksForGeeks
bool BFS(std::vector<int> graph[], int src, int dest, int pred[], int dist[]);
/// getDistance between two edges
///@param Graph[] Array Graph for storing my graph
///@param start starting edge
///@param dest destination edge
///@returns true if dest was found otherwise false
///@note Inspired by GeeksForGeeks
int getDistance(std::vector<int> graph[], int start, int dest);
/// finding biggest distance from arr[]
///@param Graph[] Array Graph for storing my graph
///@param n size of array
///@returns biggest distance
int largestDistance(int arr[], int n);
/// finding the centrer of the graph from eccentricity points
///@param eccentricityPoints array of eccentricityPonits
	  void findCenter(int* eccentricityPoints);
///get eccentricity points from all paths between nodes
///@param Graph[] Array Graph for storing my graph
///@returns array of all Eccentricities
int* getEccentricity(std::vector<int> graph[]);
/// adding edges to the graph
///@param Graph[] Array Graph for storing my graph
///@param src edge
///@param dest destination edge
void addEdge(std::vector<int> graph[], int src, int dest);
/// setting all important things in the program
///@param file object of class fileloader
 void setGraph(FileLoader file);
};

