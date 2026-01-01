// #DP

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Item
{
    int t, value, h;
};

const int MAXN = 105;
int dp[MAXN][MAXN];
Item item[MAXN];

int Solve(int n, int depth)
{
    sort(item + 1, item + n + 1, [](Item x, Item y) {
        return x.t < y.t;
    });
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 10;

    int maxLast = 10;
    for (int i = 1; i <= n; i++) {
        int t = item[i].t, value = item[i].value, h = item[i].h;
        for (int j = depth - 1; j >= 0; j--) {
            if (dp[i - 1][j] < t)
                continue;
            if (j + h >= depth)
                return t;
            dp[i][j + h] = max(dp[i][j + h], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + value);
            maxLast = max(maxLast, dp[i][j]);
        }
    }
    return maxLast;
}

int main()
{
    int n, depth;
    cin >> depth >> n;
    for (int i = 1; i <= n; i++)
        cin >> item[i].t >> item[i].value >> item[i].h;
    int ans = Solve(n, depth);
    cout << ans << endl;
}