// #Probabilities

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
double prob[MAXN], expt[MAXN];
int inDegree[MAXN];
vector<pair<int, int>> edge[MAXN];

double Solve(int src, int dst)
{
    queue<int> que;
    que.push(src);
    prob[src] = 1.0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        int k = edge[u].size();
        for (auto e : edge[u]) {
            int v = e.first, w = e.second;
            prob[v] += prob[u] / k;
            expt[v] += (expt[u] + w * prob[u]) / k;

            inDegree[v]--;
            if (inDegree[v] == 0)
                que.push(v);
        }
    }
    return expt[dst];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
        inDegree[v]++;
    }
    double ans = Solve(1, n);
    cout << fixed << setprecision(2) << ans << endl;
}