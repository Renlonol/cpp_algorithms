#include "graph.h"

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);
    //g.print();

    int v = atoi(argv[2]);
    DepthFirstSearch df(g, v);
    //df.dfs(g, v);
    df.path(g);

    for (int v = 0; v < g.get_vertex_num(); v++)
        if (df.is_marked(v))
            std::cout << v << " ";
    std::cout << std::endl;

    if (df.get_count() != g.get_vertex_num())
        std::cout << "Not connected." << std::endl;

    for (int v = 0; v < g.get_vertex_num(); v++)
    {
        std::cout << df.get_start() << " to " << v << ": ";
        if (df.is_hasPath(v))
        {
            auto path = df.get_path(v);
            for (auto v : path)
                if (v == df.get_start())
                    std::cout << v;
                else
                    std::cout << "-" << v;
        }
        std::cout << std::endl;
    }

    return 0;
}