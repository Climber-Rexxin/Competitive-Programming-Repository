// #DP

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55, INF = 0x3f3f3f3f;
int a[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];

int Dfs(int x1, int y1, int x2, int y2)
{
    if (x1 < 1 || y1 < 1 || x2 < 1 || y2 < 1)
        return -INF;
    if (dp[x1][y1][x2][y2] >= 0)
        return dp[x1][y1][x2][y2];
    if (x1 == x2 && y1 == y2)
        return -INF;

    int maxScore = -INF;
    maxScore = max(maxScore, Dfs(x1 - 1, y1, x2 - 1, y2));
    maxScore = max(maxScore, Dfs(x1, y1 - 1, x2 - 1, y2));
    maxScore = max(maxScore, Dfs(x1 - 1, y1, x2, y2 - 1));
    maxScore = max(maxScore, Dfs(x1, y1 - 1, x2, y2 - 1));
    dp[x1][y1][x2][y2] = maxScore + a[x1][y1] + a[x2][y2];
    return dp[x1][y1][x2][y2];
}

int Solve(int m, int n)
{
    memset(dp, -0x3f, sizeof(dp));
    dp[1][1][1][1] = 0;
    return Dfs(m - 1, n, m, n - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int ans = Solve(m, n);
    cout << ans << endl;
}