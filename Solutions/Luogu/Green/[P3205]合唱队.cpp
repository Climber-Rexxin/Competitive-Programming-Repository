// #Interval-DP

#include <iostream>
using namespace std;

const int MAXN = 1e3 + 5;
const int MOD = 19650827;
int h[MAXN], dp[MAXN][MAXN][2];

int Solve(int n)
{
    for (int i = 1; i <= n; i++)
        dp[i][i][0] = 1;

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = len; r <= n; l++, r++) {
            if (h[l] < h[l + 1])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % MOD;
            if (h[l] < h[r])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % MOD;

            if (h[r] > h[r - 1])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % MOD;
            if (h[r] > h[l])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % MOD;
        }
    
    return (dp[1][n][0] + dp[1][n][1]) % MOD;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int ans = Solve(n);
    cout << ans << endl;
}