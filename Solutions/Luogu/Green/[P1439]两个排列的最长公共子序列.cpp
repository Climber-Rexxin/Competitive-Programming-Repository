// #DP

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int p1[MAXN], p2[MAXN], mapping[MAXN], lis[MAXN];

int Solve(int n)
{
    for (int i = 1; i <= n; i++)
        mapping[p1[i]] = i;
    
    int lenLis = 0;
    for (int i = 1; i <= n; i++) {
        int idxLis = lower_bound(lis + 1, lis + lenLis + 1, mapping[p2[i]]) - lis;
        lis[idxLis] = mapping[p2[i]];
        lenLis = max(lenLis, idxLis);
    }
    return lenLis;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p1[i];
    for (int i = 1; i <= n; i++)
        cin >> p2[i];
    int ans = Solve(n);
    cout << ans << endl;
    
}