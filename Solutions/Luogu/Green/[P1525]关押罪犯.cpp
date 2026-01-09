// #DSU

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e4 + 5;

class DisjointSetUnion
{
    int n, father[MAXN * 2];

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

const int MAXM = 1e5 + 5;
pair<int, pair<int, int>> info[MAXM];

int Solve(int n, int m)
{
    DisjointSetUnion dsu(n * 2);
    sort(info + 1, info + m + 1);

    for (int i = m; i >= 1; i--) {
        int u = info[i].second.first, v = info[i].second.second;
        
        if (dsu.Find(u) == dsu.Find(v))
            return info[i].first;
        else {
            dsu.Unite(u, v + n);
            dsu.Unite(v, u + n);
        }
    }
    return 0;
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        info[i] = make_pair(c, make_pair(a, b));
    }
    int ans = Solve(n, m);
    cout << ans << endl;
}