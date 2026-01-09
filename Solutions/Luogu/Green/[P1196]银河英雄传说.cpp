// #Weighted-DSU

#include <iostream>
using namespace std;

const int MAXN = 3e4 + 5;

class WeightedDisjointSetUnion
{
    int n, father[MAXN], depth[MAXN], cnt[MAXN];

public:
    WeightedDisjointSetUnion(int size) : n(size)
    {
        for (int i = 1; i <= n; i++) {
            father[i] = i;
            depth[i] = 0;
            cnt[i] = 1;
        }
    }

    int GetDepth(int x)
    {  
        return depth[x];
    }

    int Find(int x)
    {
        if (father[x] != x) {
            int f = father[x];
            father[x] = Find(f);
            depth[x] += depth[f];
        }
        return father[x];
    }

    void Unite(int x, int y)
    {
        int fx = Find(x), fy = Find(y);
        father[fy] = fx;
        depth[fy] = cnt[fx];
        cnt[fx] += cnt[fy];
        cnt[fy] = 0;
    }
};

const int MAXM = 5e5 + 5;
char opt[MAXM][2];
int node[MAXM][2];

void Solve(int n, int m)
{
    WeightedDisjointSetUnion dsu(n);

    for (int i = 1; i <= m; i++) {
        int u = node[i][0], v = node[i][1];
        if (opt[i][0] == 'M')
            dsu.Unite(v, u);
        else {
            int ans = -1;
            if (dsu.Find(u) == dsu.Find(v)) {
                ans = abs(dsu.GetDepth(u) - dsu.GetDepth(v)) - 1;
            }
            cout << ans << endl;
        }
    }
}

int main()
{
    int n = 30000, m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> opt[i] >> node[i][0] >> node[i][1];
    Solve(n, m);
}