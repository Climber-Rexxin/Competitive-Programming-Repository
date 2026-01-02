// #Bitmask-DP

#include <iostream>
using namespace std;

const int MAXN = 105;
const int MAXM = 1 << 10;

string str[MAXN];
bool ok[MAXM];
int map[MAXN], status[MAXN], dp[MAXN][MAXN][MAXN];

int Init(int n, int m)
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            map[i] <<= 1;
            if (str[i][j] == 'H')
               map[i] |= 1;
        }

    int total = 0;
    for (int i = 0; i < 1 << m; i++)
        if (!(i & (i << 1)) && !(i & (i << 2)))
            status[total++] = i;
    return total;
}

int GetDigitCnt(int x)
{
    int ans = 0;
    while (x > 0)
        ans++, x -= x & (-x);
    return ans;
}

int Solve(int n, int m)
{
    int total = Init(n, m);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < total; j++) {
            if (status[j] & map[i])
                continue;
            int digitCnt = GetDigitCnt(status[j]);

            for (int k = 0; k < total; k++) {
                if (status[j] & status[k] || status[k] & map[i - 1])
                    continue;
                    
                int &ref = dp[i][j][k];
                for (int l = 0; l < total; l++) {
                    if (status[j] & status[l] || status[k] & status[l])
                        continue;
                    if (i >= 2 && status[l] & map[i - 2])
                        continue;
                    ref = max(ref, dp[i - 1][k][l] + digitCnt);
                }
            }
        }

    int ans = 0;
    for (int i = 0; i < total; i++)
        for (int j = 0; j < total; j++)
            ans = max(ans, dp[n][i][j]);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> str[i];
    int ans = Solve(n, m);
    cout << ans << endl;
}