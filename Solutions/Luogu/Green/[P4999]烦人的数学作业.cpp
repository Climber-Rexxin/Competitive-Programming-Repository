// #Digit-DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int digit[20], dp[20][200];

int Dfs(int pos, int sum, bool limit)
{
    if (!pos)
        return sum;
    int &ref = dp[pos][sum];
    if (!limit && ~ref)
        return ref;

    int ans = 0;
    int bound = limit ? digit[pos] : 9;
    for (int i = 0; i <= bound; i++)
        ans = (ans + Dfs(pos - 1, sum + i, limit && i == bound)) % MOD;

    if (!limit)
        ref = ans;
    return ans;
}

int Calculate(ll num)
{
    int len = 0;
    while (num > 0) {
        digit[++len] = num % 10;
        num /= 10;
    }
    return Dfs(len, 0, true);
}

int Solve(ll l, ll r)
{
    memset(dp, -1, sizeof(dp));
    return (Calculate(r) - Calculate(l - 1) + MOD) % MOD;
}

int main()
{
    int t;
    ll l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ans = Solve(l, r);
        cout << ans << endl;
    }
}