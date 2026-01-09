// #Weighted-DSU
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 5e3 + 5;

class WeightedDisjointUnionSet
{
    int n, father[MAXM * 2], weight[MAXM * 2];

public:
    WeightedDisjointUnionSet(int size) : n(size)
    {
        for (int i = 1; i <= n; i++)
            father[i] = i, weight[i] = 0;
    }

    int GetWeight(int x)
    {
        return weight[x];
    }

    int Find(int x)
    {
        if (father[x] != x) {
            int f = father[x];
            father[x] = Find(f);
            weight[x] ^= weight[f];
        }
        return father[x];
    }

    void Unite(int x, int y, int w)
    {
        int fx = Find(x), fy = Find(y);
        father[fy] = fx;
        weight[fy] = w ^ weight[x] ^ weight[y];
    }
};

int lidx[MAXM], ridx[MAXM];
int idx[MAXM * 2], tmp[MAXM * 2], rk[MAXM * 2];
char response[MAXM][5];

int Discretization(int n, int *src, int *dst, int *rank)
{
    memcpy(dst, src, sizeof(src[0]) * n);
    sort(dst, dst + n);

    int size = unique(dst, dst + n) - dst;
    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(dst, dst + size, src[i]) - dst + 1;
    return size;
}

int Solve(int n, int m)
{
    for (int i = 1; i <= m; i++)
        idx[i] = lidx[i] - 1, idx[i + m] = ridx[i];
    int size = Discretization(2 * m, idx + 1, tmp + 1, rk + 1);
    WeightedDisjointUnionSet dsu(size);

    int count = 0;
    for (int i = 1; i <= m; i++) {
        int u = rk[i], v = rk[i + m], w = response[i][0] == 'o';
        if (dsu.Find(u) != dsu.Find(v)) {
            dsu.Unite(u, v, w);
        } else if (dsu.GetWeight(u) ^ dsu.GetWeight(v) != w)
            break;
        count++;
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> lidx[i] >> ridx[i] >> response[i];
    int ans = Solve(n, m);
    cout << ans << endl;
}