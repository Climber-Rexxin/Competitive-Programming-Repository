// #Interval-DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 55;
int dist[MAXN], power[MAXN];
ll dp[MAXN][MAXN][2], preSum[MAXN];

ll Solve(int n, int pos)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[pos][pos][0] = 0;
    dp[pos][pos][1] = 0;
    
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + power[i];
    ll totalPower = preSum[n];
    
    for (int len = 2; len <= n; len++)
        for (int l = 1, r = len; r <= n; l++, r++) {
            ll &lref = dp[l][r][0];
            ll lpower = totalPower - (preSum[r] - preSum[l]);
            lref = min(lref, dp[l + 1][r][0] + lpower * (dist[l + 1] - dist[l]));
            lref = min(lref, dp[l + 1][r][1] + lpower * (dist[r] - dist[l]));

            ll &rref = dp[l][r][1];
            ll rpower = totalPower - (preSum[r - 1] - preSum[l - 1]);
            rref = min(rref, dp[l][r - 1][0] + rpower * (dist[r] - dist[l]));
            rref = min(rref, dp[l][r - 1][1] + rpower * (dist[r] - dist[r - 1]));
        }
    return min(dp[1][n][0], dp[1][n][1]);    
}

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> dist[i] >> power[i];
    ll ans = Solve(n, c);
    cout << ans << endl;
}