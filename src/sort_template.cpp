#include "../include/sort_template.h"

long SortCompare::sortTime(Sort<double> &s)
{
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    if (sortName.compare("Insertion") == 0)
        s.insertion_sort();
    else if (sortName.compare("Selection") == 0)
        s.selection_sort();
    else if (sortName.compare("Shell") == 0)
        s.shell_sort();
    else if (sortName.compare("Merge") == 0)
        s.merge_sort();
    else if (sortName.compare("Quick") == 0)
        s.quick_sort();
    else {
        std::cerr << "Invalid sort name: " << sortName << std::endl;
        return 0;
    }

    gettimeofday(&tv2, NULL);
    return (tv2.tv_sec - tv1.tv_sec)*1000000 + tv2.tv_usec - tv1.tv_usec;
}

double SortCompare::timeRandomInput()
{
    double total = 0.0;
    Sort<double> s;

    for (int i = 0; i < repeat; ++i)
    {
        if (sortName.compare("Merge") == 0)
            s = Sort<double>(dataNumber, true, std::less<double>());
        else
            s = Sort<double>(dataNumber, false, std::less<double>());
        //s.show_data(std::cout);
        total += sortTime(s);
    }
    return total;
}