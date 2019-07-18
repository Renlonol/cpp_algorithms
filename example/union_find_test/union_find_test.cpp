#include "../include/union_find.h"
#include <string>
#include <sstream>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    //UF uf(std::stoi(line));
    //WeightedQuickUnionUF uf(std::stoi(line));
    WeightedQuickUnionPathCompressionUF uf(std::stoi(line));
    while (std::getline(std::cin, line)) {
        std::istringstream s_in(line);
        int p, q;
        s_in >> p;
        s_in >> q;
        if (uf.connected(p, q)) continue;
        uf.union_quick(p, q);
        std::cout << p << " " << q << std::endl;
        //uf.print(std::cout);
    }
    std::cout << uf.count() << " components" << std::endl;
}