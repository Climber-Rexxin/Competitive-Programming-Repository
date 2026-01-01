// #DAG-DP

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e4 + 5;
const int MOD = 1e4;
int inDegree[MAXN], dp[MAXN][2];
vector<pair<int, int>> edge[MAXN];

void Bfs(int src)
{
    queue<int> que;
    que.push(src);
    dp[src][0] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto e : edge[u]) {
            int v = e.first, w = e.second;
            dp[v][0] = (dp[v][0] + dp[u][0]) % MOD;
            dp[v][1] = (dp[v][1] + dp[u][1] + w * dp[u][0]) % MOD;
            inDegree[v]--;
            if (inDegree[v] == 0)
                que.push(v);
        }
    }
}

int Solve(int n, int src, int dst, int time)
{
    for (int u = 1; u <= n; u++)
        for (auto e : edge[u])
            inDegree[e.first]++;
    
    Bfs(src);
    return (dp[dst][1] + (dp[dst][0] - 1) * time) % MOD;
}

int main()
{
    int n, m, s, t, time, u, v, w;
    cin >> n >> m >> s >> t >> time;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
    }
    int ans = Solve(n, s, t, time);
    cout << ans << endl;
}