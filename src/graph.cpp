#include "graph.h"

Graph::Graph(std::istream &in)
{
    std::string word;
    in >> word; ver_num = atoi(word.c_str());
    in >> word; edge_num = atoi(word.c_str());

    for (int i = 0; i < ver_num; i++)
        adj.push_back(std::vector<int>{});

    for (int i = 0; i < edge_num; i++)
    {
        int v, w;
        in >> word; v = atoi(word.c_str());
        in >> word; w = atoi(word.c_str());
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
    edge_num++;
}

void Graph::print()
{
    std::cout << ver_num << " vertices, " << edge_num << " edges" << std::endl;
    for (int v = 0; v < ver_num; v++)
    {
        std::cout << v << ": ";
        for (int w : adj[v])
            std::cout << w << " ";
        std::cout << std::endl;
    }
}

//DepthFirstSearch
void DepthFirstSearch::dfs(Graph& g, int v)
{
    marked[v] = true;
    count++;
    for (int w : g.get_adj(v))
        if (!marked[w])
            dfs(g, w);
}
