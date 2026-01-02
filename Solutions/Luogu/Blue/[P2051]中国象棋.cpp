// #Counting-DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 105;
const int MOD = 9999973;
ll dp[2][MAXN][MAXN];

ll Solve(int n, int m)
{
    int tag = 0;
    dp[tag][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        tag = !tag;
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m - j; k++) {
                ll &ref = dp[tag][j][k];
                ref = dp[!tag][j][k];
                if (j >= 1)
                    ref = (ref + dp[!tag][j - 1][k] * (m - j - k + 1)) % MOD;
                if (j >= 2)
                    ref = (ref + dp[!tag][j - 2][k] * (m - j - k + 2) * (m - j - k + 1) / 2) % MOD;
                if (j + 1 <= m && k >= 1)
                    ref = (ref + dp[!tag][j + 1][k - 1] * (j + 1)) % MOD;
                if (j + 2 <= m && k >= 2)
                    ref = (ref + dp[!tag][j + 2][k - 2] * (j + 2) * (j + 1) / 2) % MOD;
                if (j >= 1 && k >= 1)
                    ref = (ref + dp[!tag][j][k - 1] * j * (m - j - k + 1)) % MOD;
            }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m - i; j++)
            ans = (ans + dp[tag][i][j]) % MOD;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = Solve(n, m);
    cout << ans << endl;
}