// #DP #Greedy

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 205;
const int MAXM = 4e4 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN], dp[MAXN][MAXM];
pair<int, int> item[MAXN];

int Solve(int n)
{
    for (int i = 1; i <= n; i++) {
        item[i].first = b[i];
        item[i].second = a[i];
    }
    sort(item + 1, item + n + 1, greater<pair<int, int>>());
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += item[i].second;
        for (int j = 0; j <= total; j++) {
            if (j >= item[i].second) {
                int time1 = max(dp[i - 1][j - item[i].second], j + item[i].first);
                dp[i][j] = min(dp[i][j], time1);
            }
            int time2 = max(dp[i - 1][j], total - j + item[i].first);
            dp[i][j] = min(dp[i][j], time2);
        }
    }

    int ans = INF;
    for (int i = 0; i <= total; i++)
        ans = min(ans, dp[n][i]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    int ans = Solve(n);
    cout << ans << endl;
}