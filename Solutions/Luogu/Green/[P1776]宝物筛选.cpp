// #Knapsack-DP

#include <iostream>
using namespace std;

const int MAXN = 105;
const int MAXM = 4e4 + 5;
int value[MAXN], cost[MAXN], cnt[MAXN], dp[MAXM];

void Update(int itemCost, int itemValue, int w)
{
    for (int i = w; i >= itemCost; i--)
        dp[i] = max(dp[i], dp[i - itemCost] + itemValue);
}

int Solve(int n, int w)
{
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while ((j << 1) - 1 <= cnt[i]) {
            Update(j * cost[i], j * value[i], w);
            j <<= 1;
        }
        j = cnt[i] - j + 1;
        if (j > 0)
            Update(j * cost[i], j * value[i], w);
    }
    return dp[w];
}

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> value[i] >> cost[i] >> cnt[i];
    int ans = Solve(n, w);
    cout << ans << endl;
}