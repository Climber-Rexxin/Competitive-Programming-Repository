// #DP

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int score[MAXN][3], dp[3][MAXN][3][2];

int Solve(int n)
{
    memset(dp, -INF, sizeof(dp));
    for (int tail = 0; tail < 3; tail++) {
        for (int head = 0; head < 3; head++)
            if (tail != head)
                dp[tail][1][head][tail > head] = score[1][head];

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++) {
                    if (j == k)
                        continue;
                    int &ref = dp[tail][i][j][k > j];
                    ref = max(ref, dp[tail][i - 1][k][k < j] + score[i][j]);
            }
        }
    }

    int ans = -INF;
    for (int i = 0; i < 3; i++)
        ans = max({ans, dp[i][n][i][0], dp[i][n][i][1]});
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> score[i][j];
    int ans = Solve(n);
    cout << ans << endl;
}