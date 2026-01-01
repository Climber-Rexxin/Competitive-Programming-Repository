// #Tree-DP

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 3e3 + 5;
int dp[MAXN][MAXN], value[MAXN], cnt[MAXN];
vector<pair<int, int>> edge[MAXN];

void Dfs(int u)
{
    dp[u][0] = 0;
    if (edge[u].empty()) {
        cnt[u] = 1;
        dp[u][1] = value[u];
        return;
    }

    for (auto e : edge[u]) {
        int v = e.first, w = e.second;
        Dfs(v);
        cnt[u] += cnt[v];
        for (int i = cnt[u]; i >= 0; i--)
            for (int j = 1; j <= min(cnt[v], i); j++)
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] - w);
    }
}

int Solve(int n, int m)
{
    memset(dp, -0x3f, sizeof(dp));
    Dfs(1);

    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (dp[1][i] >= 0)
            ans = i;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int u = 1; u <= n - m; u++) {
        int k, v, w;
        cin >> k;
        while (k--) {
            cin >> v >> w;
            edge[u].push_back(make_pair(v, w));
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> value[i];
    int ans = Solve(n, m);
    cout << ans << endl;
}