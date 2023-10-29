#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int from, int to) {
        adjList[from].push_back(to);
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        DFSUtil(startVertex, visited);
    }
};

int main() {
    int numVertices = 6;
    
    Graph g(numVertices);

    g.addEdge(0, 3);
    g.addEdge(0, 7);
    g.addEdge(1, 9);
    g.addEdge(1, 11);
    g.addEdge(2, 13);
    g.addEdge(3, 17);
    g.addEdge(4, 19);

    cout << "\nDFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}