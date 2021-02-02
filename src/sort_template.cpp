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
    else if (sortName.compare("Heap") == 0)
        s.heap_sort();
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
        {
            if (!log_enable)
                s = Sort<double>(dataNumber, true, false, false, std::less<double>());
            else
            {
                std::cout << "start " << sortName << ", repeat " << i << ":" << std::endl;
                s = Sort<double>(dataNumber, true, true, false, std::less<double>());
            }
        }
        else if (sortName.compare("Heap") == 0)
        {
            if (!log_enable)
                s = Sort<double>(dataNumber, false, false, true, std::less<double>());
            else
            {
                std::cout << "start " << sortName << ", repeat " << i << ":" << std::endl;
                s = Sort<double>(dataNumber, false, true, true, std::less<double>());
            }
        }
        else
        {
            if (!log_enable)
                s = Sort<double>(dataNumber, false, false, false, std::less<double>());
            else
            {
                std::cout << "start " << sortName << ", repeat " << i << ":" << std::endl;
                s = Sort<double>(dataNumber, false, true, false, std::less<double>());
            }
        }
        total += sortTime(s);
    }
    return total;
}