// #Interval-DP

#include <iostream>
using namespace std;

const int MAXN = 105;
int a[MAXN * 2], dp[MAXN * 2][MAXN * 2];

int Solve(int n)
{
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i];

    for (int i = 2; i <= n; i++)
        for (int l = 1, r = l + i - 1; r < n * 2; l++, r++)
            for (int k = l; k < r; k++)
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
                
    int ans = 0;
    for (int i = 1; i + n - 1 < n * 2; i++)
        ans = max(ans, dp[i][i + n - 1]);
    return ans;
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