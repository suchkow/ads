#include <iostream>
#include <vector>
#include <string>


class DisjointSetUnion
{
public:
    DisjointSetUnion() { _parent = std::vector<int>(10, -1); }
    explicit DisjointSetUnion(unsigned int size) { _parent = std::vector<int>(size, -1); }

    int find_set(int v)
    {
        int root = v;
        while (_parent[root] != -1)
            root = _parent[root];

        while (_parent[v] != -1)
        {
            int next = _parent[v];
            _parent[v] = root;
            v = next;
        }

        return root;
    }

    void union_set(int a, int b) { _parent[find_set(a)] = find_set(b); }

private:
    std::vector<int> _parent;
};


int main() {
    std::string clause;
    DisjointSetUnion dsu;

    while (std::cin >> clause)
    {
        if (clause == "CHECK")
        {
            int a = 0;
            int b = 0;
            std::cin >> a;
            std::cin >> b;

            if (dsu.find_set(a) == dsu.find_set(b))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }

        if (clause == "JOIN")
        {
            int a = 0;
            int b = 0;
            std::cin >> a;
            std::cin >> b;

            if (dsu.find_set(a) == dsu.find_set(b))
                std::cout << "ALREADY " << a << ' ' << b << std::endl;
            else
                dsu.union_set(a, b);
        }

        if (clause == "RESET")
        {
            int size = 0;
            std::cin >> size;

            dsu = DisjointSetUnion(size);
            std::cout << "RESET DONE" << std::endl;
        }
    }

    return 0;
}