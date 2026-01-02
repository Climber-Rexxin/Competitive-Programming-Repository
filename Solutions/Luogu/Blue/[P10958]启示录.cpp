// #Digit-DP #Binary-Search

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int digit[12];
ll dp[12][3][2];

ll Dfs(int pos, int preCnt, bool ok, bool limit)
{
    if (!pos)
        return ok;
    ll &ref = dp[pos][preCnt][ok];
    if (!limit && ~ref)
        return ref;
    
    ll ans = 0;
    int bound = limit ? digit[pos] : 9;
    for (int i = 0; i <= bound; i++) {
        if (i == 6)
            ans += Dfs(pos - 1, min(preCnt + 1, 2), ok || preCnt == 2, limit && i == bound);
        else
            ans += Dfs(pos - 1, 0, ok, limit && i == bound);
    }
    ref = ans;
    return ans;
}

ll Calculate(ll num)
{
    memset(dp, -1, sizeof(dp));
    int len = 0;
    while (num > 0) {
        digit[++len] = num % 10;
        num /= 10;
    }
    return Dfs(len, 0, false, true);
}

ll Solve(int x)
{
    ll l = 666, r = 1e10;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (Calculate(mid) >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        ll ans = Solve(x);
        cout << ans << endl;
    }
}