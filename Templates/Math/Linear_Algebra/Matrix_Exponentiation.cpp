typedef long long ll;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;

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
						ans[i][j] = (ans[i][j] + num[i][k] * t[k][j]) % MOD;
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