// #DSU

#include <iostream>
using namespace std;

const int MAXN = 1e3 + 5;

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

const int MAXM = 5e3 + 5;
char opt[MAXM][2];
int node[MAXM][2];
bool vis[MAXN];

int Solve(int n, int m)
{
    DisjointSetUnion dsu(n * 2);
    
    for (int i = 1; i <= m; i++) {
        int u = node[i][0], v = node[i][1];
        if (opt[i][0] == 'F')
            dsu.Unite(u, v);
        else {
            dsu.Unite(u, v + n);
            dsu.Unite(v, u + n);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;

        ans++;
        for (int j = i + 1; j <= n; j++)
            if (!vis[j] && dsu.Find(i) == dsu.Find(j))
                vis[j] = true;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> opt[i] >> node[i][0] >> node[i][1];
    int ans = Solve(n, m);
    cout << ans << endl;
}