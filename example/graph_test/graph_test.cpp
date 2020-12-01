#include "graph.h"

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);
    //g.print();

    int v = atoi(argv[2]);
    DepthFirstSearch df(g.get_vertex_num());
    df.dfs(g, v);
    for (int v = 0; v < g.get_vertex_num(); v++)
        if (df.is_marked(v))
            std::cout << v << " ";
    std::cout << " ";

    if (df.get_count() != g.get_vertex_num())
        std::cout << "Not connected." << std::endl;
    return 0;
}