// Matrix-DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 12;
const int MOD = 1e9 + 7;

class Matrix
{
    int n, m;
    int num[MAXN][MAXN];

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
                        ans[i][j] = (ans[i][j] + 1LL * num[i][k] * t[k][j]) % MOD;
        return ans;
    }

    Matrix operator^(ll b)
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

int Solve(ll k)
{
    if (k == 1)
        return 10;

    Matrix base(10, 10);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            base[i][j] = (abs(i - j) <= 2);

    Matrix dp(10, 1);
    for (int i = 2; i <= 10; i++)
        dp[i][1] = 1;

    dp = (base ^ (k - 1)) * dp;

    int ans = 0;
    for (int i = 1; i <= 10; i++)
        ans = (ans + dp[i][1]) % MOD;
    return ans;
}

int main()
{
    ll k;
    cin >> k;
    int ans = Solve(k);
    cout << ans << endl;
}