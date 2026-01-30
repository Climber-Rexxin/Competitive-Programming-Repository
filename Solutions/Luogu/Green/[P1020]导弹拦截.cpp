// #DP

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], lds[MAXN], lis[MAXN];

pair<int, int> Solve(int n)
{
    int lenLis = 0, lenLds = 0;
    for (int i = 1; i <= n; i++) {
        int idxLds = upper_bound(lds + 1, lds + lenLds + 1, a[i], greater<int>()) - lds;
        lds[idxLds] = a[i];
        lenLds = max(lenLds, idxLds);
        
        int idxLis = lower_bound(lis + 1, lis + lenLis + 1, a[i]) - lis;
        lis[idxLis] = a[i];
        lenLis = max(lenLis, idxLis);
    }
    return make_pair(lenLds, lenLis);
}

int main()
{
    int n = 0, tmp;
    while (cin >> tmp)
        a[++n] = tmp;
    pair<int, int> ans = Solve(n);
    cout << ans.first << endl << ans.second << endl;
}