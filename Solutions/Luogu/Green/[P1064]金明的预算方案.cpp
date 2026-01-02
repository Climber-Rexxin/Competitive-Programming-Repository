// #Knapsack-DP

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 65;
const int MAXM = 3.2e4 + 5;
int dp[2][MAXM], val[MAXN], p[MAXN], f[MAXN];
vector<int> edge[MAXN];

void BuildItem(vector<pair<int, int>> &itemVec, int cost, int value, int father)
{
    int fatherCost = val[father], fatherValue = val[father] * p[father];
    itemVec.push_back(make_pair(cost + fatherCost, value + fatherValue));
}

int Solve(int n, int m)
{
    int tag = 0;
    for (int u = 1; u <= n; u++) {
        if (f[u] != 0)
            continue;
        tag = !tag;
        
        vector<pair<int, int>> itemVec;
        int allCost = 0, allValue = 0;
        BuildItem(itemVec, 0, 0, u);
        for (int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            int curCost = val[v], curValue = val[v] * p[v];
            BuildItem(itemVec, curCost, curValue, u);
            allCost += curCost;
            allValue += curValue;
        }
        if (edge[u].size() == 2)
           BuildItem(itemVec, allCost, allValue, u);
            
        for (int i = 1; i <= m; i++) {
            dp[tag][i] = dp[!tag][i];

            for (auto item : itemVec) {
                int cost = item.first, value = item.second;
                if (cost > i)
                    continue;
                dp[tag][i] = max(dp[tag][i], dp[!tag][i - cost] + value);
            }
        }
    }
    return dp[tag][m];
}

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> p[i] >> f[i];
        edge[f[i]].push_back(i);
    }
    int ans = Solve(n, m);
    cout << ans << endl;
}