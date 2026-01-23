// #SOS-DP

#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int num[MAXN], dp[1 << 20], pow2[MAXN];

int GetBitCount(int x)
{
    int ans = 0;
    while (x > 0)
        ans++, x &= x - 1;
    return ans;
}

int Solve(int n, int m)
{
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[num[i]]++;
        pow2[i] = 2LL * pow2[i - 1] % MOD;
    }

    for (int i = 0; i < m; i++)
        for (int j = 1; j < (1 << m); j++)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
    
    int ans = 0, orSum = (1 << m) - 1, subset = orSum;
    do {
        int sign = GetBitCount(subset ^ orSum) & 1 ? -1 : 1;
        ans = (ans + (sign * pow2[dp[subset]] + MOD) % MOD) % MOD;
        subset = (subset - 1) & orSum;
    } while (subset != orSum);
    return ans;
}

int main()
{
    int n, m, k, tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++)
            cin >> tmp, num[i] |= 1 << (tmp - 1);
    }
    int ans = Solve(n, m);
    cout << ans << endl;
}