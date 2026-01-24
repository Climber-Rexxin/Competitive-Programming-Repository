// #DP

#include <iostream>
using namespace std;

const int MAXN = 355;
int a[MAXN], bCnt[5], dp[45][45][45][45];

int Solve(int n)
{
    dp[0][0][0][0] = a[1];
    for (int i = 0; i <= bCnt[1]; i++)
        for (int j = 0; j <= bCnt[2]; j++)
            for (int k = 0; k <= bCnt[3]; k++)
                for (int l = 0; l <= bCnt[4]; l++) {
                    int maxScore = 0;
                    if (i > 0)
                        maxScore = max(maxScore, dp[i - 1][j][k][l]);
                    if (j > 0)
                        maxScore = max(maxScore, dp[i][j - 1][k][l]);
                    if (k > 0)
                        maxScore = max(maxScore, dp[i][j][k - 1][l]);
                    if (l > 0)
                        maxScore = max(maxScore, dp[i][j][k][l - 1]);
                    dp[i][j][k][l] = maxScore + a[1 + i + 2 * j + 3 * k + 4 * l];    
                }
    return dp[bCnt[1]][bCnt[2]][bCnt[3]][bCnt[4]];
}

int main()
{
    int n, m, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b, bCnt[b]++;
    int ans = Solve(n);
    cout << ans << endl;
}