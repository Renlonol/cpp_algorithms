#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>

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
    DepthFirstSearch(Graph& g, int v): s(v), count(0)
    {
        for (int i = 0; i < g.get_vertex_num(); i++) {
            marked.push_back(false);
            edgeTo.push_back(i);
        }
    }

    ~DepthFirstSearch() {};

    void dfs(Graph& g, int v);
    bool is_marked(int w) const { return marked[w]; }
    int get_count() const { return count; }
    int get_start() const { return s; }
    void path(Graph& g);
    bool is_hasPath(int v) { return marked[v]; }
    std::vector<int> get_path(int v);
    void print_path(int v);

private:
    std::vector<bool> marked;
    std::vector<int> edgeTo; // store the last vertex of from start vertex(s) to certain vertex
    int s;
    int count;
};

class BreadthFirstSearch
{
public:
    BreadthFirstSearch(Graph& g, int v);
    ~BreadthFirstSearch() {}

    void bfs(Graph& g, int v);
    bool is_hasPath(int v) { return marked[v]; }
    void path(Graph& g);
    std::vector<int> get_path(int v);
    void print_path(int v);

private:
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int s;
};