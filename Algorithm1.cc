#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasDirectedCycle(int n, const vector<vector<int>>& graph) {
    vector<int> inDegree(n, 0);

    // Count incoming arrows for every vertex.
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    queue<int> sources;

    // Put all sources (vertices with no incoming arrows) in the queue.
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            sources.push(i);
        }
    }

    int removedVertices = 0;

    // Repeatedly remove sources.
    while (!sources.empty()) {
        int source = sources.front();
        sources.pop();
        removedVertices++;

        // Remove all outgoing arrows from this source.
        for (int neighbour : graph[source]) {
            inDegree[neighbour]--;

            // This neighbour has become a source.
            if (inDegree[neighbour] == 0) {
                sources.push(neighbour);
            }
        }
    }

    // If some vertices could not be removed, they form or contain a cycle.
    return removedVertices != n;
}

int main() {
    int n = 4;   // Vertices: a=0, b=1, c=2, d=3

    vector<vector<int>> graph(n);

    // Edges: a->b, b->c, c->a, a->d
    graph[0].push_back(1); // a -> b
    graph[0].push_back(3); // a -> d
    graph[1].push_back(2); // b -> c
    graph[2].push_back(0); // c -> a

    if (hasDirectedCycle(n, graph)) {
        cout << "The graph contains a directed cycle." << endl;
    } else {
        cout << "The graph is acyclic." << endl;
    }

    return 0;
}