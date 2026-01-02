// #Interval-DP

#include <iostream>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;
int a[MAXN], preSum[MAXN];
int dpMin[MAXN][MAXN][10], dpMax[MAXN][MAXN][10];

int GetSum(int l, int r)
{
    return (preSum[r] - preSum[l - 1] + 10) % 10;
}

pair<int, int> Solve(int n, int m)
{
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i] = ((a[i] % 10) + 10) % 10;

    for (int i = 1; i <= 2 * n; i++) {
        preSum[i] = (preSum[i - 1] + a[i]) % 10;
        dpMin[i][i][1] = dpMax[i][i][1] = a[i];
    }

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = l + len - 1; r < 2 * n; l++, r++) {
            dpMin[l][r][1] = dpMax[l][r][1] = GetSum(l, r);

            for (int i = 2; i <= min(len, m); i++) {
                dpMin[l][r][i] = INF;
                dpMax[l][r][i] = -INF;
                for (int j = l + i - 2; j < r; j++) {
                    dpMin[l][r][i] = min(dpMin[l][r][i], dpMin[l][j][i - 1] * dpMin[j + 1][r][1]);
                    dpMax[l][r][i] = max(dpMax[l][r][i], dpMax[l][j][i - 1] * dpMax[j + 1][r][1]);
                }
            }
        }

    int ansMin = INF, ansMax = -INF;
    for (int i = 1; i <= n; i++) {
        ansMin = min(ansMin, dpMin[i][i + n - 1][m]);
        ansMax = max(ansMax, dpMax[i][i + n - 1][m]);
    }
    return make_pair(ansMin, ansMax);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto ans = Solve(n, m);
    cout << ans.first << endl << ans.second << endl;
}