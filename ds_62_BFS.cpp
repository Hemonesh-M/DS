#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int from, int to) {
        adjList[from].push_back(to);
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
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

    cout << "\nBFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}