// #Interval-DP

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 35;
int a[MAXN], root[MAXN][MAXN], preorder[MAXN];
ll dp[MAXN][MAXN];

void PreorderTraversal(int l, int r, int &idx)
{
    preorder[idx++] = root[l][r];

    if (l <= root[l][r] - 1)
        PreorderTraversal(l, root[l][r] - 1, idx);

    if (root[l][r] + 1 <= r)
        PreorderTraversal(root[l][r] + 1, r, idx);
}

int Solve(int n)
{
    for (int i = 1; i <= n; i++) {
        dp[i][i] = a[i];
        root[i][i] = i;
    }

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = l + len - 1; r <= n; l++, r++)
            for (int i = l; i <= r; i++) {
                ll lscore = l <= i - 1 ? dp[l][i - 1] : 1;
                ll rscore = i + 1 <= r ? dp[i + 1][r] : 1;
                if (lscore * rscore + a[i] >= dp[l][r]) {
                    dp[l][r] = lscore * rscore + a[i];
                    root[l][r] = i;
                }
            }
    
    int idx = 1;
    PreorderTraversal(1, n, idx);

    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];
    ll ans = Solve(n);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << preorder[i] << (i == n ? '\n' : ' ');
}