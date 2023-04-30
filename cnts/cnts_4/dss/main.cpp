#include <iostream>
#include <vector>
#include <string>


class DisjointSetUnion
{
public:
    DisjointSetUnion()
    {
        for (int i = 0; i < 10; ++i)
        {
            _parent.push_back(i);
            _level.push_back(0);
        }
    }
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