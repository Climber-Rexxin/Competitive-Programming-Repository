// #DP

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 5e3 + 5;
const int MOD = 998244353;
int a[MAXN], cnt[MAXN], dp[MAXN];

int Solve(int n)
{
    int maxCnt = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        maxCnt = max(maxCnt, ++cnt[a[i]]);

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n; cnt[i] && j >= cnt[i]; j--)
            dp[j] = (dp[j] + 1LL * dp[j - cnt[i]] * cnt[i]) % MOD;

    int ans = 0;
    for (int i = maxCnt; i <= n; i++)
        ans = (ans + dp[i]) % MOD;
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = Solve(n);
        cout << ans << endl;
    }
}