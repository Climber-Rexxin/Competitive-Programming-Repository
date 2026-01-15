// #Thinking

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e8 - 3;

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

int p1[MAXN], p2[MAXN], mapping[MAXN];
int rk1[MAXN], rk2[MAXN], tmp[MAXN];

void Discretization(int n, int *src, int *dst, int *rank)
{
    memcpy(dst, src, sizeof(src[0]) * n);
    sort(dst, dst + n);

    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(dst, dst + n, src[i]) - dst + 1;
}

int Solve(int n)
{
    Discretization(n, p1 + 1, tmp, rk1 + 1);
    Discretization(n, p2 + 1, tmp, rk2 + 1);
    for (int i = 1; i <= n; i++)
        mapping[rk1[i]] = i;
    BinaryIndexedTree tree(n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + i - 1 - tree.Query(mapping[rk2[i]]) + MOD) % MOD;
        tree.Update(mapping[rk2[i]]);
    }
    return ans;
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