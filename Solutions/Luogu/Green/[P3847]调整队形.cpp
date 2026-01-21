// #Interval-DP

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 3e3 + 5;
int a[MAXN], dp[MAXN][MAXN];

int Solve(int n)
{
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = dp[i][i - 1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int l = 1, r = l + i - 1; r <= n; l++, r++) {
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
            dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + (a[l] != a[r]));
        }
    }
    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = Solve(n);
    cout << ans << endl;
}