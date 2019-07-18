#ifndef SORT_TEMPLATE_H
#define SORT_TEMPLATE_H

#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<functional> 
#include <sys/time.h>
#include <unistd.h>
#include<random>

template <typename T> class Sort {
public:
    typedef typename std::vector<T>::size_type size_type;
    Sort() = default;
    Sort(std::istream& In, bool aux_enable, std::function<bool(const T&, const T&)> cf);
    Sort(int N, bool aux_enable, std::function<bool(const T&, const T&)> cf);
    void selection_sort();
    void insertion_sort();
    void shell_sort();
    void merge_sort();
    void quick_sort();
    std::ostream& show_data(std::ostream &os);
private:
    std::shared_ptr<std::vector<T>> data;
    std::shared_ptr<std::vector<T>> aux_data;
    std::function<bool(const T&, const T&)> compFunc;
    void merge(int low, int mid, int high);
    void merge_sort_impl(int low, int high);
    int partition(int low, int high);
    void quick_sort_impl(int low, int high);
};

class SortCompare {
public:
    SortCompare() = default;
    SortCompare(std::string &name, int n, int r):
        sortName(name), dataNumber(n), repeat(r) {}
    long sortTime(Sort<double> &);
    double timeRandomInput();
private:
    std::string sortName;
    int dataNumber;
    int repeat;
};


template <typename T>
Sort<T>::Sort(std::istream &In, bool aux_enable, std::function<bool(const T&, const T&)> cf):
    data(std::make_shared<std::vector<T>>()), compFunc(cf)
{
    T word;
    while (In >> word)
        data->push_back(word);
    if (aux_enable)
        aux_data = std::make_shared<std::vector<T>>(data->size());
}

template <typename T>
Sort<T>::Sort(int N, bool aux_enable, std::function<bool(const T&, const T&)> cf):
    data(std::make_shared<std::vector<T>>()), compFunc(cf)
{
    std::default_random_engine random(time(NULL));
    std::uniform_real_distribution<T> dis(0.0, N);

    for (int i = 0; i < N; ++i)
        data->push_back(dis(random));
    if (aux_enable)
        aux_data = std::make_shared<std::vector<T>>(data->size());
}

template <typename T>
std::ostream& Sort<T>::show_data(std::ostream &os)
{
    for (auto d : *data)
        os << d << " ";
    os << std::endl;
    return os;
}

template <typename T>
void Sort<T>::selection_sort()
{
    for(size_type i  = 0; i < data->size() - 1; ++i)
    {
        size_type minIndex = i;
        for (size_type j = i; j < data->size() - 1; ++j)
        {
            if (compFunc((*data)[j+1], (*data)[minIndex]))
                minIndex = j + 1;
        }
        std::swap((*data)[i], (*data)[minIndex]);
    }
    //show_data(std::cout);
}

template <typename T>
void Sort<T>::insertion_sort()
{
    for (size_type i = 1; i < data->size(); ++i)
    {
        for (size_type j = i; j > 0 && compFunc((*data)[j], (*data)[j-1]); --j)
            std::swap((*data)[j], (*data)[j-1]);
    }
    //show_data(std::cout);
}

template <typename T>
void Sort<T>::shell_sort()
{
    size_type N = data->size();
    size_type h = 1;
    while (h < N/3)
        h = 3*h + 1;
    while (h >= 1) {
        for (size_type i = h; i < N; i++) {
            for (size_type j = i; j >= h && compFunc((*data)[j], (*data)[j-h]); j -= h)
                std::swap((*data)[j], (*data)[j-h]);
        }
        h = h / 3;
    }
    //show_data(std::cout);
}

template <typename T>
void Sort<T>::merge(int low, int mid, int high)
{
    int i = low, j = mid + 1;
    
    for (int k = low; k <= high; k++)
        (*aux_data)[k] = (*data)[k];
    
    for (int k = low; k <= high; k++)
    {
        if (i > mid)
            (*data)[k] = (*aux_data)[j++];
        else if (j > high)
            (*data)[k] = (*aux_data)[i++];
        else if (compFunc((*aux_data)[i], (*aux_data)[j]))
            (*data)[k] = (*aux_data)[i++];
        else
            (*data)[k] = (*aux_data)[j++];
    }
}

template <typename T>
void Sort<T>::merge_sort_impl(int low, int high)
{
    if (high <= low)
        return;
    int mid = low + (high - low) / 2;
    merge_sort_impl(low, mid);
    merge_sort_impl(mid+1, high);
    merge(low, mid, high);
}

template <typename T>
void Sort<T>::merge_sort()
{
    merge_sort_impl(0, data->size() - 1);
    //show_data(std::cout);
}

template <typename T>
int Sort<T>::partition(int low, int high)
{
    int i = low, j = high + 1;
    T v = (*data)[low];

    while (true) {
        while (compFunc((*data)[++i], v)) 
            if (i == high) break;
        while (compFunc(v, (*data)[--j]))
            if (j == low)  break;

        if (i >= j) break; 
        std::swap((*data)[i], (*data)[j]);
    }
    std::swap((*data)[low], (*data)[j]);
    return j;
}

template <typename T>
void Sort<T>::quick_sort_impl(int low, int high)
{
    if (low >= high)
        return;
    int j = partition(low, high);
    quick_sort_impl(low, j-1);
    quick_sort_impl(j+1, high);
}

template <typename T>
void Sort<T>::quick_sort()
{
    quick_sort_impl(0, data->size() - 1);
    //show_data(std::cout);
}

#endif