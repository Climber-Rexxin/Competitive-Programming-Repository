const int MAXN = 1e5 + 5;

class DisjointSetUnion
{
    int n, father[MAXN];

public:
    DisjointSetUnion(int size) : n(size)
    {
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }

    inline int Find(int x)
    {
        return father[x] == x ? x : father[x] = Find(father[x]);
    }

    void Unite(int x, int y)
    {
        father[Find(y)] = Find(x);
    }
};