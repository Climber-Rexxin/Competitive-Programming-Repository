// #DP

#include <iostream>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 205;
const int MOD = 1e9 + 7;
char a[MAXN], b[MAXN];
int dp[2][MAXM][MAXM];

int Solve(int n, int m, int cnt)
{
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int k = 1; k <= cnt; k++) {
                dp[0][j][k] = 0;
                if (a[i] != b[j])
                    continue;
                dp[0][j][k] = (dp[1][j - 1][k - 1] + dp[0][j - 1][k]) % MOD;
                dp[1][j][k] = (dp[1][j][k] + dp[0][j][k]) % MOD;
            }
    return dp[1][m][cnt];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k >> a + 1 >> b + 1;
    int ans = Solve(n, m, k);
    cout << ans << endl;
}