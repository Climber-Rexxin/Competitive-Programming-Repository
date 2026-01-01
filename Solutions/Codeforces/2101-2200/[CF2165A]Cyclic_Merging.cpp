// #Greedy #Link-List

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
int a[MAXN], idx[MAXN], pre[MAXN], nxt[MAXN];

void Delete(int x) {
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x]; 
}

ll Solve(int n)
{
    for (int i = 0; i < n; i++)
        idx[i] = i, nxt[i] = (i + 1) % n, pre[i] = (i - 1 + n) % n;
    sort(idx, idx + n, [](int x, int y) {
        return a[x] < a[y];
    });

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int node = idx[i];
        ans += min(a[pre[node]], a[nxt[node]]);
        Delete(node);
    }
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = Solve(n);
        cout << ans << endl;
    }
}