// #Matrix-DP

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e3 + 5;
int MOD;

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

	Matrix operator*(Matrix &mat)
	{
		Matrix ans(n, mat.m);
		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= m; k++)
				if (num[i][k])
					for (int j = 1; j <= mat.m; j++)
						ans[i][j] = (ans[i][j] + num[i][k] * mat[k][j]) % MOD;
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

ll Solve(ll p, ll q, ll a1, ll a2, ll n)
{
    if (n == 1)
        return a1;

    Matrix base(2, 2), f(2, 1);
    base[1][1] = p;
    base[1][2] = q;
    base[2][1] = 1;
    f[1][1] = a2;
    f[2][1] = a1;

    f = (base ^ (n - 2)) * f;
    return f[1][1];
}

int main()
{
    ll p, q, a1, a2, n, m;
    cin >> p >> q >> a1 >> a2 >> n >> MOD;
    ll ans = Solve(p, q, a1, a2, n);
    cout << ans << endl;
}