// #Interval-DP

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55;
char str[MAXN];
int dp[MAXN][MAXN];

int Solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
            if (str[l] == str[r]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r]);
                dp[l][r] = min(dp[l][r], dp[l][r - 1]);
            }

            for (int i = l; i < r; i++) 
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
        }
    return dp[1][n];
}

int main()
{
    cin >> str + 1;
    int ans = Solve();
    cout << ans << endl;
}