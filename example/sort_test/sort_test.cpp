#include "../../include/sort_template.h"
#include <string>


static void usage()
{
    std::cout << "./sort_test [sort type] [sort type] [data num] [repeats] [log_enable]" << std::endl;
    std::cout << "sort type: Insertion, Selection, Shell, Heap, Merge, Quick" << std::endl;
    std::cout << "eg, ./sort_test Merge Quick 10000000 1 1" << std::endl;
}

int main(int argc, char **argv)
{
    // Sort<std::string> s(std::cin, std::less<std::string>());
    // //Sort<std::string> s(std::cin, std::greater<std::string>());
    // s.show_data(std::cout);
    // //s.selection_sort();
    // //s.insertion_sort();
    // s.shell_sort();
    // s.show_data(std::cout);

    if (argc <= 5) {
        usage();
        return 0;
    }


    std::string sortname1(argv[1]);
    std::string sortname2(argv[2]);
    int dataNum = std::stoi(argv[3]);
    int repeats = std::stoi(argv[4]);
    bool log_enable = (std::stoi(argv[5]) == 0) ? false : true;

    SortCompare sc1(sortname1, dataNum, repeats, log_enable);
    SortCompare sc2(sortname2, dataNum, repeats, log_enable);

    double t1 = sc1.timeRandomInput();
    double t2 = sc2.timeRandomInput();

    std::cout << "For " << dataNum <<" random Doubles" << std::endl;
    std::cout << "    " << sortname1 << " is " << t2 / t1 << " times faster than " << sortname2 << std::endl;
    return 0;
}