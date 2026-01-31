// #DP

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 805;
const int MOD = 1e9 + 7;
int score[MAXN][MAXN], dp[2][MAXN][2][20];

int Solve(int n, int m, int volume)
{
    int tag = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        tag = !tag;
        for (int j = 1; j <= m; j++) {
            int delta = score[i][j] % volume;
            for (int k = 0; k < volume; k++) {
                int src1 = (k - delta + volume) % volume;
                dp[tag][j][0][k] = (dp[!tag][j][1][src1] + dp[tag][j - 1][1][src1]) % MOD;

                int src2 = (k + delta) % volume;
                dp[tag][j][1][k] = (dp[!tag][j][0][src2] + dp[tag][j - 1][0][src2]) % MOD;
            }
            dp[tag][j][0][delta] = (dp[tag][j][0][delta] + 1) % MOD;
            
            ans = (ans + dp[tag][j][1][0]) % MOD;
        }
    }
    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> score[i][j];
    int ans = Solve(n, m, k + 1);
    cout << ans << endl;
}