#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
#include <vector>


class UF {
public:
    UF(int N);
    int count() { return cnt; }
    void union_quick(int p, int q);
    int find(int p) { return id[p]; }
    bool connected(int p, int q) { return find(p) == find(q); }
    std::ostream& print(std::ostream&);
private:
    std::vector<int> id; //store component id
    int cnt; //number of components
};

class WeightedQuickUnionUF {
public:
    WeightedQuickUnionUF(int N);
    int count() { return cnt; }
    void union_quick(int p, int q);
    int find(int p);
    bool connected(int p, int q) { return find(p) == find(q); }
private:
    std::vector<int> id; //store component id
    std::vector<int> weight; //store component id weight
    int cnt; //number of components
};

class WeightedQuickUnionPathCompressionUF{
public:
    WeightedQuickUnionPathCompressionUF(int N);
    int count() { return cnt; }
    void union_quick(int p, int q);
    int find(int p);
    bool connected(int p, int q) { return find(p) == find(q); }
private:
    std::vector<int> id; //store component id
    std::vector<int> weight; //store component id weight
    int cnt; //number of components
};

#endif