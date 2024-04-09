// Implement Graph Traversal techniques:
// a) Depth First Search b) Breadth First Search

#include <iostream>
using namespace std;
#define MAX_VERTICES 100


class Graph
{
private:
    int vertices;
    int adjacency[MAX_VERTICES][MAX_VERTICES];

public:

    Graph(int V)
    {
        vertices = V;

        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                adjacency[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjacency[u][v] = 1;
        adjacency[v][u] = 1; 
    }


    void DFSUtil(int vertex, bool visited[])
    {
        cout << vertex << " ";
        visited[vertex] = true;
        for (int i = 0; i < vertices; ++i)
        {
            if (adjacency[vertex][i] && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        bool visited[MAX_VERTICES] = {false};
        cout << "Depth First Search Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Breadth First Search traversal starting from a given vertex
    void BFS(int start)
    {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        cout << "Breadth First Search Traversal: ";
        visited[start] = true;
        queue[rear++] = start;

        while (front != rear)
        {
            int current = queue[front++];
            cout << current << " ";
            for (int i = 0; i < vertices; ++i)
            {
                if (adjacency[current][i] && !visited[i])
                {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.DFS(0);
    g.BFS(0);

    return 0;
}
