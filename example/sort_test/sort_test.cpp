#include "../../include/sort_template.h"
#include <string>


int main(int argc, char **argv)
{
    // Sort<std::string> s(std::cin, std::less<std::string>());
    // //Sort<std::string> s(std::cin, std::greater<std::string>());
    // s.show_data(std::cout);
    // //s.selection_sort();
    // //s.insertion_sort();
    // s.shell_sort();
    // s.show_data(std::cout);


    std::string sortname1(argv[1]);
    std::string sortname2(argv[2]);
    int dataNum = std::stoi(argv[3]);
    int repeats = std::stoi(argv[4]);

    SortCompare sc1(sortname1, dataNum, repeats);
    SortCompare sc2(sortname2, dataNum, repeats);

    double t1 = sc1.timeRandomInput();
    double t2 = sc2.timeRandomInput();

    std::cout << "For " << dataNum <<" random Doubles" << std::endl;
    std::cout << "    " << sortname1 << " is " << t2 / t1 << " times faster than " << sortname2 << std::endl;
    return 0;
}