// #Data-Structures

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
const int MOD = 92084931;

class BinaryIndexedTree
{
    int n, cnt[MAXN];

    int Lowbit(int x)
    {
        return x & (-x);
    }

public:
    BinaryIndexedTree(int size) : n(size)
    {
        memset(cnt, 0, sizeof(cnt));
    }

    void Update(int idx)
    {
        while (idx <= n) {
            cnt[idx]++;
            idx += Lowbit(idx);
        }
    }

    int Query(int idx)
    {
        int ans = 0;
        while (idx > 0) {
            ans += cnt[idx];
            idx -= Lowbit(idx);
        }
        return ans;
    }
};

int a[MAXN];
ll preSum[MAXN], tmp[MAXN], rk[MAXN];

int Discretization(int n, ll *src, ll *dst, ll *rank)
{
    memcpy(dst, src, sizeof(src[0]) * n);
    sort(dst, dst + n);
    int size = unique(dst, dst + n) - dst;

    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(dst, dst + size, src[i]) - dst + 1;
    return size;
}

ll Solve(int n, int m)
{
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + a[i] - m;

    int size = Discretization(n, preSum + 1, tmp + 1, rk + 1);
    BinaryIndexedTree tree(size);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + tree.Query(rk[i] - 1) + (preSum[i] > 0)) % MOD;
        tree.Update(rk[i]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = Solve(n, m);
    cout << ans << endl;
}