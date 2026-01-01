// #Rerooting-DP

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
ll dp[MAXN][2], size[MAXN];
vector<int> edge[MAXN];

void Dfs1(int u, int f)
{
    size[u] = 1;
    for (int v : edge[u]) {
        if (v == f)
            continue;
        Dfs1(v, u);
        dp[u][0] += dp[v][0] + size[v];
        size[u] += size[v];
    }
}

void Dfs2(int u, int f, int n)
{
    for (int v : edge[u]) {
        if (v == f)
            continue;
        ll sibling = dp[u][0] - dp[v][0] - size[v];
        dp[v][1] = dp[u][1] + sibling + n - size[v];
        Dfs2(v, u, n);
    }
}

int Solve(int n)
{
    Dfs1(1, 1);
    Dfs2(1, 1, n);

    ll maxDepSum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i][0] + dp[i][1] > maxDepSum) {
            maxDepSum = dp[i][0] + dp[i][1];
            ans = i;
        }
    return ans;
}

int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans = Solve(n);
    cout << ans << endl;
}