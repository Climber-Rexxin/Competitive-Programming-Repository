// #DP #Probability

#include <iostream>
using namespace std;

const int MAXN = 1e7 + 5;
const int MOD = 20040313;
int inv[MAXN], dp[MAXN];

void GetInv(int n, int p)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = 1LL * (p - p / i) * inv[p % i] % p;
}

int Solve(int n)
{
    GetInv(n, MOD);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        dp[i] = (dp[i + 1] + 1LL * n * inv[n - i]) % MOD;
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    int ans = Solve(n);
    cout << ans << endl;
}