// #Bitmask-DP

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 3e5 + 5;
int status[9], deltaX[4] = {-2, 0, 2, 0}, deltaY[4] = {0, -2, 0, 2};
ll x[MAXN], y[MAXN], c[MAXN], dp[MAXN][1 << 4];

void Init()
{
    for (int i = 0; i < 4; i++) {
        status[i] |= 1 << i;
        status[(i + 1) % 4] |= 1 << i;
        status[i + 4] = 1 << i;
    }
    status[8] = (1 << 4) - 1;
    memset(dp[0], -0x7f, sizeof(dp[0]));
    dp[0][0] = 0;
}

ll GetLength(int side, int idx)
{
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        if (side & (1 << i))
            ans += deltaX[i] * x[idx] + deltaY[i] * y[idx];
    }
    return ans;
}

ll Solve(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << 4); j++) {
            dp[i][j] = dp[i - 1][j] + c[i];
            for (int k = 0; k < 9; k++) {
                if ((j & status[k]) == status[k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j ^ status[k]] + GetLength(status[k], i));
            }
        }
    }
    return dp[n][(1 << 4) - 1];
}

int main()
{
    int t, n;
    cin >> t;
    Init();
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= n; i++)
            cin >> y[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        ll ans = Solve(n);
        cout << ans << endl;    
    }
}