#include <iostream>
#include <list>


class Graph
{
    int vert_amount;
    std::list<int>* list_adj;
    bool* visited;

public:
    Graph(int amount);
    void add_edge(int src, int dest);
    void bfs(int vert_start);
};


// Create a graph with given amount, and maintain an adjacency list
Graph::Graph(int amount)
{
    vert_amount = amount;
    list_adj = new std::list<int>[amount];
}

void Graph::add_edge(int src, int dest)
{
    list_adj[src].push_back(dest);
    list_adj[dest].push_back(src);
}

void Graph::bfs(int vert_start)
{
    visited = new bool[vert_amount];
    for (int i = 0; i < vert_amount; i++)
        visited[i] = false;

    std::list<int> queue;

    visited[vert_start] = true;
    queue.push_back(vert_start);

    std::list<int>::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = list_adj[currVertex].begin(); i != list_adj[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    g.bfs(2);

    return 0;
}