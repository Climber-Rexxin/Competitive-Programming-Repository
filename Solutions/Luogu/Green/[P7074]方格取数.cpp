// #DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int a[MAXN][MAXN];
ll dp[MAXN][MAXN], preMax[MAXN], sufMax[MAXN];

ll Solve(int n, int m)
{
    memset(dp, -0x3f, sizeof(dp));
    preMax[0] = sufMax[n + 1] = -INF;
    dp[0][1] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            preMax[j] = max(dp[i - 1][j], preMax[j - 1]) + a[j][i];
        for (int j = n; j >= 1; j--)
            sufMax[j] = max(dp[i - 1][j], sufMax[j + 1]) + a[j][i];
        for (int j = 1; j <= n; j++)
            dp[i][j] = max(preMax[j], sufMax[j]);
    }
    return dp[m][n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    ll ans = Solve(n, m);
    cout << ans << endl;
}