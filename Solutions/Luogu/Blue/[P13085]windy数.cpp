// #Digit-DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int digit[20];
ll dp[20][2][10];

ll Dfs(int pos, bool ok, int last, bool limit, bool lead)
{
    if (!pos)
        return ok;
    ll &ref = dp[pos][ok][last];
    if (!limit && !lead && ~ref)
        return ref;

    ll ans = 0;
    int bound = limit ? digit[pos] : 9;
    for (int i = 0; i <= bound; i++) {
        bool flag = lead || abs(i - last) >= 2;
        ans += Dfs(pos - 1, ok && flag, i, limit && i == bound, lead && !i);
    }

    if (!limit && !lead)
        ref = ans;
    return ans;
}

ll Calculate(ll num)
{
    int len = 0;
    while (num > 0)
        digit[++len] = num % 10, num /= 10;
    return Dfs(len, true, 0, true, true);
}

ll Solve(ll l, ll r)
{
    memset(dp, -1, sizeof(dp));
    return Calculate(r) - Calculate(l - 1);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = Solve(a, b);
    cout << ans << endl;
}