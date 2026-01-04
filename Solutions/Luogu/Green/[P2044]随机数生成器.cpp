// #Matrix-DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 3;
ll MOD;

ll SMul(ll a, ll b)
{
    ll ans = 0;
    while (b > 0) {
        if (b & 1)
            ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}

class Matrix
{
    int n, m;
    ll num[MAXN][MAXN];

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

    ll *operator[](int i)
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
                        ans[i][j] = (ans[i][j] + SMul(num[i][k], t[k][j])) % MOD;
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

ll Solve(ll a, ll c, ll f0, ll n, ll g)
{
    Matrix base(2, 2);
    base[1][1] = a;
    base[1][2] = 1;
    base[2][2] = 1;

    Matrix f(2, 1);
    f[1][1] = f0;
    f[2][1] = c;

    f = (base ^ n) * f;
    return f[1][1] % g;
}

int main()
{
    ll a, c, f0, n, g;
    cin >> MOD >> a >> c >> f0 >> n >> g;
    ll ans = Solve(a, c, f0, n, g);
    cout << ans << endl;
}