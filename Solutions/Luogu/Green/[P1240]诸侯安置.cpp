// #Counting-DP

#include <iostream>
using namespace std;

const int MOD = 504;
int dp[100][200];

int Perm2(int n)
{
    return n * (n - 1);
}

int Solve(int n, int num)
{
    if (num > 2 * n - 1)
        return 0;

    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        int total = 2 * i - 1;
        for (int j = 0; j <= min(total, num); j++) {
            if (j >= 2)
                dp[i][j] += dp[i - 1][j - 2] * Perm2(total - (j - 2)) % MOD;
            if (j >= 1)
                dp[i][j] += dp[i - 1][j - 1] * (total - (j - 1)) * 2 % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }

    int ans = dp[n - 1][num];
    if (num >= 1)
        ans = (ans + dp[n - 1][num - 1] * (2 * n - num)) % MOD;
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = Solve(n, k);
    cout << ans << endl;
}