// #Greedy

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
ll a[MAXN], s[MAXN], tmp[MAXN];

ll Solve(int n)
{
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    ll avg = s[n] / n;
    for (int i = 1; i <= n; i++)
        s[i] -= i * avg;

    memcpy(tmp + 1, s + 1, sizeof(s[0]) * n);
    int k = (n + 1) / 2;
    nth_element(tmp + 1, tmp + k, tmp + n + 1);
    int median = tmp[k];
    
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += abs(s[i] - median);
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = Solve(n);
    cout << ans << endl;
}