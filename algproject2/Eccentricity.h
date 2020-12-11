#pragma once
#include <vector>
#pragma once
class Eccentricity
{
public: void FindGraphCenter();
private:bool BFS(std::vector<int> adj[], int src, int dest, int pred[], int dist[], int number_of_nodes);
	   int GetDistance(std::vector<int> graph[], int start, int dest, int number_of_nodes);
	   int largest_distance(int arr[], int n);
	   void find_centre(int* eccentricity_points, int number_of_nodes);
	   int* get_eccentricity(std::vector<int> graph[], int number_of_nodes);
};

