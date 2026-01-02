// #Tree-DP

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105;
const int MAXM = 3e4 + 5;
int dp[MAXN][MAXM], cnt[MAXN];
vector<pair<int, int>> edge[MAXN];

void Dfs(int u, int f)
{
    for (auto e : edge[u]) {
        int v = e.first, w = e.second;
        if (v == f)
            continue;
        Dfs(v, u);

        cnt[u] += cnt[v] + 1;
        for (int i = cnt[u]; i >= 1; i--)
            for (int j = 1; j <= min(cnt[v] + 1, i); j++)
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j - 1] + w);
    }
}

int Solve(int m)
{
    Dfs(1, -1);
    return dp[1][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }
    int ans = Solve(m);
    cout << ans << endl;
}