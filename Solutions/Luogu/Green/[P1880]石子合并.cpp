// #Interval-DP

#include <iostream>
using namespace std;

const int MAXN = 1e2 + 5;
int a[MAXN * 2], preSum[MAXN * 2];
int dpMin[MAXN * 2][MAXN * 2], dpMax[MAXN * 2][MAXN * 2];

pair<int, int> Solve(int n)
{
    for (int i = 1; i <= n * 2; i++) {
        if (i > n)
            a[i] = a[i - n];
        preSum[i] = preSum[i - 1] + a[i];
    }

    for (int i = 2; i <= n; i++)
        for (int l = 1, r = l + i - 1; r < n * 2; l++, r++) 
        {
            int sum = preSum[r] - preSum[l - 1];
            dpMin[l][r] = 0x7fffffff, dpMax[l][r] = 0;
            for (int k = l; k < r; k++) {
                dpMin[l][r] = min(dpMin[l][r], dpMin[l][k] + dpMin[k + 1][r] + sum);
                dpMax[l][r] = max(dpMax[l][r], dpMax[l][k] + dpMax[k + 1][r] + sum);
            }
        }
        
    int ansMin = 0x7fffffff, ansMax = 0;
    for (int i = 1; i <= n; i++) {
        ansMin = min(ansMin, dpMin[i][i + n - 1]);
        ansMax = max(ansMax, dpMax[i][i + n - 1]);
    }
    return make_pair(ansMin, ansMax);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto ans = Solve(n);
    cout << ans.first << endl << ans.second << endl;
}