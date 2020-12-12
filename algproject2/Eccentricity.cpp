#include "Eccentricity.h"
#include <iostream>
#include <list>
#include "FileLoader.h"

void Eccentricity::FindGraphCenter()
	{
		FileLoader File;
		File.loadGraph();
		int number_of_nodes = File.GetNodes();
		std::vector<int>* graph = new std::vector<int>[number_of_nodes];
		int *src = new int[number_of_nodes]();
		int* dest = new int[number_of_nodes]();
		src = File.Getsrc();
		dest = File.Getdest();
		int rows = File.getRows();
		int j = 0;
	    while(j != rows)
	    {
		    add_edge(graph, src[j], dest[j]);
			j++;
	    }

		int* eccentricity_points = new int[number_of_nodes]();
		eccentricity_points = get_eccentricity(graph, number_of_nodes);
		find_centrer(eccentricity_points, number_of_nodes);
}

void Eccentricity::add_edge(std::vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
// function to form edge between two vertices
// source and dest
	// a modified version of BFS that stores predecessor
	// of each vertex in array p
	// and its distance from source in array d
	bool Eccentricity::BFS(std::vector<int> adj[], int src, int dest,
	         int pred[], int dist[], int number_of_nodes)
	{
		// a queue to maintain queue of vertices whose
		// adjacency list is to be scanned as per normal
		// DFS algorithm
		std::list<int> queue;

		// boolean array visited[] which stores the
		// information whether ith vertex is reached
		// at least once in the Breadth first search
		bool* visited = new bool[number_of_nodes];

		// initially all vertices are unvisited
		// so v[i] for all i is false
		// and as no path is yet constructed
		// dist[i] for all i set to infinity
		for (int i = 0; i < number_of_nodes; i++)
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
			for (int i = 0; i < adj[u].size(); i++)
			{
				if (visited[adj[u][i]] == false)
				{
					visited[adj[u][i]] = true;
					dist[adj[u][i]] = dist[u] + 1;
					pred[adj[u][i]] = u;
					queue.push_back(adj[u][i]);

					// We stop BFS when we find
					// destination.
					if (adj[u][i] == dest)
						return true;
				}
			}
		}
		return false;
	}

	// utility function to calculate the shortest distance
	// between two vertex
	int Eccentricity::GetDistance(std::vector<int> graph[], int start,
	                int dest, int number_of_nodes)
	{
		// predecessor[i] array stores predecessor of
		// i and distance array stores distance of i
		// from start
		int* pred = new int[number_of_nodes];
		int* dist = new int[number_of_nodes];

		if (BFS(graph, start, dest, pred, dist, number_of_nodes) == false)
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

	int Eccentricity::largest_distance(int arr[], int n)
	{
		// Initialize maximum element 
		int max = arr[0];

		// Traverse array elements  
		// from second and compare 
		// every element with current max  
		for (int i = 1; i < n; i++)
			if (arr[i] > max)
				max = arr[i];
		return max;
	}

	//finding the centre of the graph from eccentricity points
	void Eccentricity::find_centrer(int* eccentricity_points, int number_of_nodes)
	{
		std::vector<int> centre_points;
		//lowest index of array eccentricty_points setted
		int tmp = eccentricity_points[0];
		for (int i = 1; i < number_of_nodes; i++)
		{
			//if lower value was found clear vector and save new value
			if (tmp > eccentricity_points[i])
			{
				tmp = eccentricity_points[i];
				centre_points.clear();
				centre_points.push_back(i);
				continue;
			}
			//if same value was found push there another value
			if (tmp == eccentricity_points[i]) centre_points.push_back(i);
		}
		//write out Centrer points
		std::cout << "Center points of graph are: ";
		for (int i = 0; i < centre_points.size(); i++) std::cout << centre_points.at(i) << ' ';
	}

	//get eccentricity points from all paths between nodes
	int* Eccentricity::get_eccentricity(std::vector<int> graph[], int number_of_nodes)
	{
		int* eccentricity_points = new int[number_of_nodes]();
	    //find path to every node from one node and find longest path then save it
		for (int i = 0; i < number_of_nodes; i++)
		{
			int* array = new int[number_of_nodes];
			for (int j = 0; j < number_of_nodes; j++)
			{
				array[j] = GetDistance(graph, i, j, number_of_nodes);
			}
			eccentricity_points[i] = largest_distance(array, number_of_nodes);
			delete[] array;
		}
		return eccentricity_points;
	}

