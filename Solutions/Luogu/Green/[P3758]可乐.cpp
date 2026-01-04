// #Matrix-DP

#include <iostream>
using namespace std;

const int MAXN = 35;
const int MAXM = 105;
const int MOD = 2017;

class Matrix
{
    int n, m;
    int num[MAXN * 2][MAXN * 2];

public:
    Matrix(int n, int m) : n(n), m(m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                num[i][j] = 0;
    }

    static Matrix Identity(int n)
    {
        Matrix id(n, n);
        for (int i = 1; i <= n; i++)
            id[i][i] = 1;
        return id;
    }

    int *operator[](int i)
    {
        return num[i];
    }

    Matrix operator*(Matrix &t)
    {
        Matrix ans(n, t.m);
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= m; k++)
                if (num[i][k] != 0)
                    for (int j = 1; j <= t.m; j++)
                        ans[i][j] = (ans[i][j] + num[i][k] * t[k][j]) % MOD;
        return ans;
    }

    Matrix operator^(int b)
    {
        Matrix ans = Identity(n);
        Matrix a = *this;
        while (b > 0) {
            if (b & 1)
                ans = ans * a;
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
};

int edge[MAXM][2];

int Solve(int n, int m, int t)
{
    Matrix base(2 * n, 2 * n);
    for (int i = 1; i <= m; i++) {
        int u = edge[i][0], v = edge[i][1];
        base[u][v] = base[u + n][v] = 1;
        base[v][u] = base[v + n][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        base[i][i] = 1;
        base[i + n][i] = 1;
        base[i + n][i + n] = 1;
    }
    
    Matrix dp(2 * n, 1);
    dp[1][1] = dp[1 + n][1] = 1;
    
    dp = (base ^ t) * dp;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i + n][1]) % MOD;
    return ans;
}

int main()
{
    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> edge[i][0] >> edge[i][1];
    cin >> t;
    int ans = Solve(n, m, t);
    cout << ans << endl;
}