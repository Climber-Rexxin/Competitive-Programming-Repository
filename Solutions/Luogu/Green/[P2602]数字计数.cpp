// #Digit-DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int digit[15];
ll dp[15][15][10], ans[10];

ll Dfs(int pos, int cnt, bool limit, bool lead, int idx)
{
    if (!pos)
        return cnt;
    ll &ref = dp[pos][cnt][idx];
    if (!limit && !lead && ~ref)
        return ref;

    ll ans = 0;
    int bound = limit ? digit[pos] : 9;
    for (int i = 0; i <= bound; i++) {
        int curCnt = cnt + (idx == i);
        if (idx == 0 && i == 0 && lead)
            curCnt = cnt;

        ans += Dfs(pos - 1, curCnt, limit && i == bound, lead && !i, idx);
    }

    if (!limit && !lead)
        ref = ans;
    return ans;
}

void Calculate(ll num, int delta)
{
    int len = 0;
    while (num > 0) {
        digit[++len] = num % 10;
        num /= 10;
    }
    for (int i = 0; i <= 9; i++)
        ans[i] += delta * Dfs(len, 0, true, true, i);
}

void Solve(ll l, ll r)
{
    memset(dp, -1, sizeof(dp));
    Calculate(r, 1);
    Calculate(l - 1, -1);
}

int main()
{
    ll l, r;
    cin >> l >> r;
    Solve(l, r);
    for (int i = 0; i <= 9; i++)
        cout << ans[i] << (i == 9 ? '\n' : ' ');
}