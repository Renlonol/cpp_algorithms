#include "graph.h"

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);
    //g.print();

    std::cout << "df test:" << std::endl;
    int v = atoi(argv[2]);
    DepthFirstSearch df(g, v); // from v to start depth search
    //df.dfs(g, v);
    df.path(g);

    for (int v = 0; v < g.get_vertex_num(); v++)
        if (df.is_marked(v))
            std::cout << v << " ";
    std::cout << std::endl;

    if (df.get_count() != g.get_vertex_num())
        std::cout << "Not connected." << std::endl;

    for (int v = 0; v < g.get_vertex_num(); v++)
        df.print_path(v);

    std::cout << "bf test:" << std::endl;
    BreadthFirstSearch bf(g, v);
    bf.path(g);

    for (int v = 0; v < g.get_vertex_num(); v++)
        bf.print_path(v);
    return 0;
}