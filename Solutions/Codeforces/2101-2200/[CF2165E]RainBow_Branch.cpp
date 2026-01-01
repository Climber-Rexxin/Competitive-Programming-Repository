// #Constuctive #Tree-Theory

#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 3e5 + 5;
int ans[MAXN], deg[MAXN];
vector<int> edge[MAXN];

void Solve(int n)
{
    vector<int> leaf;
    multiset<int> degSet;
    for (int i = 1; i <= n; i++) {
        deg[i] = edge[i].size();
        degSet.insert(deg[i]);
        if (deg[i] == 1)
            leaf.push_back(i);
    }

    int k = 1, removedLeaf = 0;
    for (int i = 1; i < n && removedLeaf < n; i += 2) {
        while (k <= removedLeaf + 1)
            ans[k++] = i;
        int maxDeg = *degSet.rbegin();
        while (k <= removedLeaf + maxDeg)
            ans[k++] = i + 1;

        vector<int> newLeaf;
        for (int u: leaf) {
            for (int v: edge[u]) {
                if (!deg[v])
                    continue;
                degSet.erase(degSet.find(deg[v]));
                degSet.insert(--deg[v]);
                if (deg[v] == 1)
                    newLeaf.push_back(v);
            }
            if (degSet.find(1) != degSet.end())
                degSet.erase(degSet.find(1));
            deg[u] = 0;
        }
        removedLeaf += leaf.size();
        swap(leaf, newLeaf);
    }
    return;
}

int main()
{
    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        Solve(n);
        for (int i = 1; i < n; i++)
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }
}