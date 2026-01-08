// #Thinking

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1.5e3 + 5;
const int INF = 0x3f3f3f3f;
char str[MAXN];
int graph[MAXN][MAXN];
pair<int, int> visit[MAXN][MAXN];
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

bool Dfs(int x, int y, int n, int m)
{
    bool ok = false;
    for (int i = 0; i < 4 && !ok; i++) {
        int nxtx = x + dirx[i], nxty = y + diry[i];
        int realx = (nxtx % n + n) % n;
        int realy = (nxty % m + m) % m;
        if (graph[realx][realy] == 1)
            continue;
        
        auto &tag = visit[realx][realy];
        if (tag.first == INF) {
            tag = make_pair(nxtx, nxty);
            ok |= Dfs(nxtx, nxty, n, m);
        } else if (tag.first == nxtx && tag.second == nxty)
            continue;
        else
            ok = true;
    }
    return ok;
}

bool Solve(int srcx, int srcy, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visit[i][j] = make_pair(INF, INF);
    return Dfs(srcx, srcy, n, m);
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        int srcx, srcy;
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < m; j++) {
                graph[i][j] = str[j] == '#' ? 1 : 0;

                if (str[j] == 'S')
                    srcx = i, srcy = j;
            }
        }
        bool ok = Solve(srcx, srcy, n, m);
        cout << (ok ? "Yes" : "No") << endl;
    }
}