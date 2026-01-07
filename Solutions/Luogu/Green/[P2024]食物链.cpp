// #DSU

#include <iostream>
using namespace std;

const int MAXN = 5e4 + 5;
const int MAXK = 1e5 + 5;

class DisjointSetUnion
{
    int n, father[MAXN * 3];

public:
    DisjointSetUnion(int size) : n(size)
    {
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }

    int Find(int x)
    {
        return father[x] == x ? x : father[x] = Find(father[x]);
    }

    void Union(int x, int y)
    {
        father[Find(y)] = Find(x);
    }
};

int op[MAXK], x[MAXK], y[MAXK];

bool IsSameSet(DisjointSetUnion &dsu, int x, int y)
{
    return dsu.Find(x) == dsu.Find(y);
}

int Solve(int n, int k)
{
    DisjointSetUnion dsu(n * 3);

    int ans = k;
    for (int i = 1; i <= k; i++) {
        if (x[i] > n || y[i] > n)
            continue;
        
        if (op[i] == 1) {
            if (IsSameSet(dsu, x[i], y[i] + n))
                continue;
            if (IsSameSet(dsu, x[i], y[i] + 2 * n))
                continue;
                
            if (!IsSameSet(dsu, x[i], y[i]))
                for (int j = 0; j < 3; j++)
                    dsu.Union(x[i] + j * n, y[i] + j * n);
        } else {
            if (IsSameSet(dsu, x[i], y[i]))
                continue;
            if (IsSameSet(dsu, x[i], y[i] + 2 * n))
                continue;

            if (!IsSameSet(dsu, x[i], y[i] + n))
                for (int j = 0; j < 3; j++)
                    dsu.Union(x[i] + j * n, y[i] + (j + 1) % 3 * n);
        }
        ans--;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> op[i] >> x[i] >> y[i];
    int ans = Solve(n, k);
    cout << ans << endl;
}