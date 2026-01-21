// #DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 5e3 + 5;
int t[MAXN], f[MAXN], preSum1[MAXN], preSum2[MAXN];
ll dp[MAXN];

ll Solve(int n, int s)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        preSum1[i] = preSum1[i - 1] + t[i];
        preSum2[i] = preSum2[i - 1] + f[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ll cost1 = 1LL * preSum1[i] * (preSum2[i] - preSum2[j]);
            ll cost2 = 1LL * s * (preSum2[n] - preSum2[j]);
            dp[i] = min(dp[i], dp[j] + cost1 + cost2);
        }
    }
    return dp[n];
}

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> f[i];
    ll ans = Solve(n, s);
    cout << ans << endl;
}