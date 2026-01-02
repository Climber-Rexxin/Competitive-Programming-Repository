// #Tree-DP

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 305;
int dp[MAXN][MAXN], cnt[MAXN], value[MAXN];
vector<int> edge[MAXN];

void Dfs(int u, int m)
{
    cnt[u] = 1;
    dp[u][1] = value[u];
    for (int v : edge[u]) {
        Dfs(v, m);
        cnt[u] += cnt[v];
        for (int i = min(cnt[u], m); i >= 1; i--)
            for (int j = 1; j <= min(cnt[v], i - 1); j++)
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
    }
}

int Solve(int n, int m)
{
    Dfs(0, m + 1);
    return dp[0][m + 1];
}

int main()
{
    int n, m, f;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> f >> value[i];
        edge[f].push_back(i);
    }
    int ans = Solve(n, m);
    cout << ans << endl;
}