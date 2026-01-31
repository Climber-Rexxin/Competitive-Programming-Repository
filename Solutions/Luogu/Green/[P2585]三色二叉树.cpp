// #Tree-DP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 5;
char str[MAXN];
int son[MAXN][2], dpMax[MAXN][3], dpMin[MAXN][3];

vector<int> edge[MAXN];

int BuildTree(int l)
{
    int sonCnt = str[l] - '0', r = l;
    for (int i = 0; i < sonCnt; i++) {
        son[l][i] = r + 1;
        r = BuildTree(r + 1);
    }
    return r;
}

void Dfs(int root)
{
    int lson = son[root][0], rson = son[root][1];
    if (!lson)
        dpMax[root][0] = dpMin[root][0] = 1;
    else if (!rson) {
        Dfs(lson);
        for (int i = 0; i < 3; i++) {
            int c1 = (i + 1) % 3, c2 = (i + 2) % 3;
            dpMax[root][i] = max(dpMax[lson][c1], dpMax[lson][c2]) + (i == 0);
            dpMin[root][i] = min(dpMin[lson][c1], dpMin[lson][c2]) + (i == 0);
        }
    } else {
        Dfs(lson);
        Dfs(rson);
        for (int i = 0; i < 3; i++) {
            int c1 = (i + 1) % 3, c2 = (i + 2) % 3;
            int maxSum1 = dpMax[lson][c1] + dpMax[rson][c2];
            int maxSum2 = dpMax[lson][c2] + dpMax[rson][c1];
            int minSum1 = dpMin[lson][c1] + dpMin[rson][c2];
            int minSum2 = dpMin[lson][c2] + dpMin[rson][c1];
            
            dpMax[root][i] = max(maxSum1, maxSum2) + (i == 0);
            dpMin[root][i] = min(minSum1, minSum2) + (i == 0);
        }
    }
}

pair<int, int> Solve()
{
    BuildTree(1);
    Dfs(1);

    int ansMax = max({dpMax[1][0], dpMax[1][1], dpMax[1][2]});
    int ansMin = min({dpMin[1][0], dpMin[1][1], dpMin[1][2]});
    return make_pair(ansMax, ansMin);
}

int main()
{
    cin >> (str + 1);
    auto ans = Solve();
    cout << ans.first << " " << ans.second << endl;
}