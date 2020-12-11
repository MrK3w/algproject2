#define _CRT_SECURE_NO_WARNINGS
// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
int number_of_nodes = 0;
FILE* file;
// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest,
    int pred[], int dist[], int number_of_nodes)
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool* visited = new bool[number_of_nodes];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < number_of_nodes; i++) {
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
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
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

// utility function to print the shortest distance
// between source vertex and destination vertex
int GetDistance(vector<int> adj[], int s,
    int dest, int number_of_nodes)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int* pred = new int[number_of_nodes];
    int* dist = new int[number_of_nodes];

    if (BFS(adj, s, dest, pred, dist, number_of_nodes) == false) {
        return 0;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    return dist[dest];
}
int largest(int arr[], int n)
{
    int i;

    // Initialize maximum element 
    int max = arr[0];

    // Traverse array elements  
    // from second and compare 
    // every element with current max  
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void getPath(int* result)
{
    vector<int> g1;
    int compare = result[0];
    for (int i = 1; i < number_of_nodes; i++)
    {
        if (compare > result[i])
        {
            compare = result[i];
            g1.clear();
            g1.push_back(i);
            continue;
        }
        if (compare == result[i]) g1.push_back(i);
    }
    std::cout << "Body centru grafu jsou: ";
    for (int i = 0; i < g1.size(); i++) std::cout << g1.at(i) << ' ';
}

int* Distance(vector<int> adj[])
{
    int* result = new int[number_of_nodes]();
    for (int i = 0; i < number_of_nodes; i++)
    {
        int* array = new int[number_of_nodes];
        for (int j = 0; j < number_of_nodes; j++)
        {
            array[j] = GetDistance(adj, i, j, number_of_nodes);
        }
        result[i] = largest(array, number_of_nodes);
        delete[] array;
    }
    return result;
}

void openFile()
{
    file = fopen("graf.txt", "r");
}

void closeFile()
{
    fclose(file);
}

int GetNodes()
{
    fscanf(file, "%d", &number_of_nodes);
    return number_of_nodes;
}

vector<int>* loadGraph()
{
    int src, dest;
    openFile();
    GetNodes();
    vector<int>* adj = new vector<int>[number_of_nodes];
    while ((fscanf(file, "%d %d\n", &src, &dest)) != EOF) add_edge(adj, src, dest);
    return adj;
}

int main()
{
    vector<int>* adj = loadGraph();
    int* result = new int[number_of_nodes]();
    result = Distance(adj);
    getPath(result);
}