#include <iostream>
#include <vector>


class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(int size)
    {
        for (int i = 0; i < size; ++i)
        {
            _parent.push_back(i);
            _level.push_back(0);
        }
    }

    int find_set(int v)
    {
        if (v != _parent[v])
            _parent[v] = find_set(_parent[v]);
        return _parent[v];
    }

    bool union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return false;

        if (_level[a] < _level[b])
            std::swap(a, b);

        _parent[b] = a;
        if (_level[a] == _level[b])
            ++_level[a];

        return true;
    }

private:
    std::vector<int> _parent;
    std::vector<int> _level;
};


struct Vertex {
    int from;
    int to;
    int weight;
};

bool operator < (Vertex a, Vertex b) {
    return a.weight < b.weight;
}


int main() {
    int N;
    int M;
    std::cin >> N;
    std::cin >> M;

    std::vector<Vertex> vertices;

    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        vertices.push_back({from, to, weight});
    }

    sort(vertices.begin(), vertices.end());

    DisjointSetUnion dsu(N);

    int total_weight = 0;
    int total_edges = 0;
    for (Vertex vertex : vertices)
    {
        if (total_edges == N - 1)
            break;

        if (dsu.union_set(vertex.from, vertex.to))
        {
            total_weight += vertex.weight;
            ++total_edges;
        }
    }

    if (total_edges == N - 1)
        std::cout << total_weight << std::endl;
    else
        std::cout << "NON-CONNECTED" << std::endl;

    return 0;
}