// #Combinatorics

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;
int charCnt[26], perm[MAXN], comb[MAXN][MAXN];

void Init(int n)
{
    perm[0] = comb[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        perm[i] = 1LL * perm[i - 1] * i % MOD;
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }
}

int Solve(int n, string str)
{
    Init(n);
    for (char ch : str)
        charCnt[ch - 'a']++;
    
    int inverse = 1, sum = n / 2, flag = 0;
    for (int i = 0; i < 26; i++) {
        if (charCnt[i] & 1)
            flag++;
        inverse = 1LL * inverse * comb[sum][charCnt[i] / 2] % MOD;
        sum -= charCnt[i] / 2;
        inverse = 1LL * inverse * perm[charCnt[i]] % MOD;
    }
    
    if (flag > 1)
        inverse = 0;
    return (perm[n] - inverse + MOD) % MOD;
}

int main()
{
    int n;
    string str;
    cin >> n >> str;
    int ans = Solve(n, str);
    cout << ans << endl;
}