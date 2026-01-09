// #DSU

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

class DisjointSetUnion
{
    int n, father[MAXN << 1];

public:
    DisjointSetUnion(int size) : n(size)
    {
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }

    int Find(int x)
    {
        return father[x] == x ? x : father[x] = Find(father[x]);
    }

    void Unite(int x, int y)
    {
        father[Find(y)] = Find(x);
    }
};

int a[MAXN], b[MAXN], e[MAXN];
int src[MAXN << 1], dst[MAXN << 1], rk[MAXN << 1];

int Discretization(int n, int *src, int *dst, int *rank)
{
    memcpy(dst, src, sizeof(src[0]) * n);
    sort(dst, dst + n);

    int size = unique(dst, dst + n) - dst;
    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(dst, dst + size, src[i]) - dst + 1;
    return size;
}

bool Solve(int n)
{
    for (int i = 1; i <= n; i++)
        src[i] = a[i], src[i + n] = b[i];
    int m = Discretization(n * 2, src + 1, dst + 1, rk + 1);
    
    DisjointSetUnion dsu(m);
    vector<int> query;
    for (int i = 1; i <= n; i++) {
        a[i] = rk[i];
        b[i] = rk[i + n];
        if (e[i])
            dsu.Unite(a[i], b[i]);
        else
            query.push_back(i);
    }

    for (int idx : query)
        if (dsu.Find(a[idx]) == dsu.Find(b[idx]))
            return false;
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> e[i];
        
        bool ok = Solve(n);
        cout << (ok ? "YES" : "NO") << endl;
    }
}