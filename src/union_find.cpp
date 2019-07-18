#include "../include/union_find.h"

UF::UF(int N): cnt(N)
{
    for (int i = 0; i < N; ++i)
        id.push_back(i);
}

std::ostream& UF::print(std::ostream& os)
{
    for(auto d : id)
        os << d << " ";
    os << std::endl;
    return os;
}

void UF::union_quick(int p, int q)
{
    int p_id = find(p);
    int q_id = find(q);
    if (p_id == q_id) return;
    for (size_t i = 0; i < id.size(); ++i) {
        if (id[i] == p_id)
            id[i] = q_id;
    }
    cnt--;
}


WeightedQuickUnionUF::WeightedQuickUnionUF(int N): cnt(N)
{
    for (int i = 0; i < N; ++i)
        id.push_back(i);
    for (int i = 0; i < N; ++i)
        weight.push_back(1);
}

int WeightedQuickUnionUF::find(int p)
{
    while (id[p] != p) p = id[p];
    return p;
}

void WeightedQuickUnionUF::union_quick(int p, int q)
{
    int p_id = find(p);
    int q_id = find(q);

    if (p_id == q_id)   return;

    if (weight[p_id] < weight[q_id])
    {
        id[p_id] = q_id;
        weight[q_id] += p_id;
    }
    else
    {
        id[q_id] = p_id;
        weight[p_id] += q_id;
    }
    cnt--;
}

WeightedQuickUnionPathCompressionUF::WeightedQuickUnionPathCompressionUF(int N):
    cnt(N)
{
    for (int i = 0; i < N; ++i)
        id.push_back(i);
    for (int i = 0; i < N; ++i)
        weight.push_back(1);
}

int WeightedQuickUnionPathCompressionUF::find(int p)
{
    int root = p;
    while (id[root] != root)
        root = id[root];
    while (id[p] != root) {
        int newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}

void WeightedQuickUnionPathCompressionUF::union_quick(int p, int q)
{
    int p_id = find(p);
    int q_id = find(q);

    if (p_id == q_id)   return;

    if (weight[p_id] < weight[q_id])
    {
        id[p_id] = q_id;
        weight[q_id] += p_id;
    }
    else
    {
        id[q_id] = p_id;
        weight[p_id] += q_id;
    }
    cnt--;
}