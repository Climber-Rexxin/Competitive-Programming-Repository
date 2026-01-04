// #Matrix-DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 12;
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

struct Ans
{
    ll a, b, c;
};

Ans Solve(ll n, ll p, ll q, ll r, ll t, ll u, ll v, ll w, ll x, ll y, ll z)
{
    Matrix base(11, 11);
    base[1][1] = p, base[1][2] = q, base[1][3] = 1, base[1][5] = 1;
    base[1][7] = r, base[1][8] = t, base[1][11] = 1;
    base[2][1] = 1;
    base[3][1] = 1, base[3][3] = u, base[3][4] = v, base[3][5] = 1, base[3][9] = 1;
    base[4][3] = 1;
    base[5][1] = 1, base[5][3] = 1, base[5][5] = x, base[5][6] = y;
    base[5][8] = 1, base[5][10] = 1, base[5][11] = 2;
    base[6][5] = 1;
    base[7][7] = 1, base[7][8] = 2, base[7][11] = 1;
    base[8][8] = 1, base[8][11] = 1;
    base[9][9] = w;
    base[10][10] = z;
    base[11][11] = 1;

    Matrix f(11, 1);
    f[1][1] = f[3][1] = f[5][1] = 3;
    f[2][1] = f[4][1] = f[6][1] = 1;
    f[7][1] = f[8][1] = 1;
    f[9][1] = w;
    f[10][1] = z;
    f[11][1] = 1;

    f = (base ^ (n - 2)) * f;
    return Ans({f[1][1], f[3][1], f[5][1]});
}

int main()
{
    ll n, p, q, r, t, u, v, w, x, y, z;
    cin >> n >> MOD >> p >> q >> r >> t;
    cin >> u >> v >> w >> x >> y >> z;
    Ans ans = Solve(n, p, q, r, t, u, v, w, x, y, z);
    cout << "nodgd " << ans.a << endl;
    cout << "Ciocio " << ans.b << endl;
    cout << "Nicole " << ans.c << endl;
}