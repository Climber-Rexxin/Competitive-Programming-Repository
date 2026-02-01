// #Interval-DP

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 205;
char idx2Ch[5] = "WING", mappingStr[4][20][3], srcStr[MAXN];
int cnt[4], ch2Idx[26], mapping[4][20][2], src[MAXN];
bool dp[MAXN][MAXN][4];

void Init(int n)
{
    for (int i = 0; i < 4; i++)
        ch2Idx[idx2Ch[i] - 'A'] = i;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < cnt[i]; j++) {
            mapping[i][j][0] = ch2Idx[mappingStr[i][j][0] - 'A'];
            mapping[i][j][1] = ch2Idx[mappingStr[i][j][1] - 'A'];
    }

    for (int i = 1; i <= n; i++)
        src[i] = ch2Idx[srcStr[i] - 'A'];

    for (int i = 1; i <= n; i++)
        dp[i][i][src[i]] = true;
}

string Solve(int n)
{
    Init(n);

    for (int len = 2; len <= n; len++)
        for (int l = 1, r = len; r <= n; l++, r++)
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < cnt[i]; j++) {
                    int lidx = mapping[i][j][0];
                    int ridx = mapping[i][j][1];
                    for (int k = l; k < r; k++)
                        dp[l][r][i] |= dp[l][k][lidx] & dp[k + 1][r][ridx];
                }

    string ans;
    for (int i = 0; i < 4; i++)
        if (dp[1][n][i])
            ans += idx2Ch[i];
    if (ans.size() == 0)
        ans = "The name is wrong!";
    return ans;
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < cnt[i]; j++) {
            cin >> mappingStr[i][j];
        }
    cin >> srcStr + 1;
    string ans = Solve(strlen(srcStr + 1));
    cout << ans << endl;
}