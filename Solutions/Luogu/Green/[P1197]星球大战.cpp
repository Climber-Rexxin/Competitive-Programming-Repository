// #DSU

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 4e5 + 5;
const int MAXM = 2e5 + 5;

class DisjointSetUnion
{
    int n, father[MAXN];

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

int ans[MAXN], node[MAXN];
bool tag[MAXN];
vector<int> edge[MAXN];

void Solve(int n, int k)
{
    DisjointSetUnion dsu(n);
    int cnt = n;
    for (int u = 1; u <= n; u++) {
        if (tag[u])
            continue;
        for (int v : edge[u])
            if (!tag[v] && dsu.Find(u) != dsu.Find(v))
               dsu.Unite(u, v), cnt--;
    }

    for (int i = k; i >= 1; i--) {
        ans[i] = cnt - i;
        int u = node[i];
        for (int v : edge[u])
            if (!tag[v] && dsu.Find(u) != dsu.Find(v))
                dsu.Unite(u, v), cnt--;
        tag[u] = false;
    }
    ans[0] = cnt;
}

int main()
{
    int n, m, k, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edge[u + 1].push_back(v + 1);
        edge[v + 1].push_back(u + 1);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> node[i];
        tag[++node[i]] = true;
    }
    Solve(n, k);
    for (int i = 0; i <= k; i++)
        cout << ans[i] << endl;
}