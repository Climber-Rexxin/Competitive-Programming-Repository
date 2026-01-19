// #Bitmask-DP

#include <iostream>
using namespace std;

typedef long long ll;
ll dp[10][1 << 9][100];

bool IsInvalid(int a, int b)
{
    return a & b || (a << 1) & b || a & (b << 1);
}

int GetBitCount(int x)
{
    int ans = 0;
    while (x > 0)
        ans++, x &= x - 1;
    return ans;
}

ll Solve(int n, int num)
{
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << n); j++) {
            if (j & (j << 1))
                continue;            
            int bitCnt = GetBitCount(j);
            for (int k = 0; k < (1 << n); k++) {
                if (k & (k << 1) || IsInvalid(j, k))
                    continue;
                for (int l = bitCnt; l <= num; l++)
                    dp[i][j][l] += dp[i - 1][k][l - bitCnt];
            }
        }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++)
        ans += dp[n][i][num];
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    ll ans = Solve(n, k);
    cout << ans << endl;
}