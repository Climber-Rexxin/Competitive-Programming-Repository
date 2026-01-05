// #Combinatorics #Data-Structures

#include <iostream>
#include <cstring>
using namespace std;

class BinaryIndexedTree
{
    static const int MAXM = 1e5 + 5;
    int n, cnt[MAXM];

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
        while (idx <= n)
            cnt[idx]++, idx += Lowbit(idx);
    }

    int Query(int idx)
    {
        int ans = 0;
        while (idx > 0)
            ans += cnt[idx], idx -= Lowbit(idx);
        return ans;
    }
};

typedef long long ll;
const int MAXN = 3e4 + 5;
int a[MAXN], preCnt[MAXN], sufCnt[MAXN];

ll Solve(int n)
{
    BinaryIndexedTree treePre(1e5);
    for (int i = 1; i <= n; i++) {
        preCnt[i] = treePre.Query(a[i] - 1);
        treePre.Update(a[i]);
    }

    BinaryIndexedTree treeSuf(1e5);
    for (int i = n; i >= 1; i--) {
        sufCnt[i] = n - i - treeSuf.Query(a[i]);
        treeSuf.Update(a[i]);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1LL * preCnt[i] * sufCnt[i];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = Solve(n);
    cout << ans << endl;
}