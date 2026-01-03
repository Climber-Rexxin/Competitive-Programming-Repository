// #Math

#include <iostream>
using namespace std;

typedef long long ll;
const ll MAXVAL = 1e12;
ll Solve(ll x, ll y, ll k)
{
    if (y == 1)
        return -1;
    while (x > 0) {
        ll q = (k - 1) / (y - 1), r = (k - 1) % (y - 1);
        if (q == 0)
            break;
        ll removeCnt = min((y - r - 2) / q + 1, x);
        k += removeCnt * q;
        x -= removeCnt;
        if (k > MAXVAL)
            return -1;
    }
    return k;
}
int main()
{
    int t;
    ll x, y, k;
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        ll ans = Solve(x, y, k);
        cout << ans << endl;
    }
}