// #DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
ll a[MAXN], s[MAXN], f[MAXN], g[MAXN], maxF[MAXN];

ll Solve(int n)
{
    ll maxDelta = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        f[i] = i - 1LL * i * i + s[i - 1];
        g[i] = i + 1LL * i * i - s[i];
        maxF[i] = max(maxF[i - 1], f[i]);
        maxDelta = max(maxDelta, maxF[i] + g[i]);
    }
    return s[n] + maxDelta;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = Solve(n);
        cout << ans << endl;
    }
}