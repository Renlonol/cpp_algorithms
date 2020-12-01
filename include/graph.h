#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

class Graph
{
public:
    //Graph(int n);
    Graph(std::istream &in);
    ~Graph() {};

    int get_vertex_num() const { return ver_num; }
    int get_edge_num() const {return edge_num; }
    void add_edge(int v, int w);
    std::vector<int>& get_adj(int v) { return adj[v]; }
    void print();
private:
    int ver_num;
    int edge_num;
    std::vector<std::vector<int>> adj;
};

class DepthFirstSearch
{
public:
    DepthFirstSearch(int n): count(0)
    {
        for (int i = 0; i < n; i++)
            marked.push_back(false);
    }

    ~DepthFirstSearch() {};

    void dfs(Graph& g, int v);
    bool is_marked(int w) const { return marked[w]; }
    int get_count() const { return count; }

private:
    std::vector<bool> marked;
    int count;
};
