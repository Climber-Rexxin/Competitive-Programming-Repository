// #DP

#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], dp[35];

int Solve(int n)
{
    for (int i = 1; i <= n; i++) {
        int maxLen = 0;
        for (int j = 0; j <= 30; j++)
            if (a[i] & (1 << j))
                maxLen = max(maxLen, dp[j]);

        for (int j = 0; j <= 30; j++)
            if (a[i] & (1 << j))
                dp[j] = maxLen + 1;
    }

    int ans = 0;
    for (int i = 0; i <= 30; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = Solve(n);
    cout << ans << endl;
}