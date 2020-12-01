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
        if (!marked[w]) {
            edgeTo[w] = v;
            dfs(g, w);
        }
}

void DepthFirstSearch::path(Graph& g)
{
    dfs(g, s);
}

std::vector<int> DepthFirstSearch::get_path(int v)
{
    if (!is_hasPath(v))
        return std::vector<int>{};

    std::vector<int> st;
    for (int x = v; x != s; x = edgeTo[x])
        st.insert(st.begin(), x);
    st.insert(st.begin(), s);
    return st;
}

void DepthFirstSearch::print_path(int v)
{
    std::cout << s << " to " << v << ": ";
    if (is_hasPath(v))
    {
        auto path = get_path(v);
        for (auto v : path)
            if (v == s)
                std::cout << v;
            else
                std::cout << "-" << v;
    }
    std::cout << std::endl;
}