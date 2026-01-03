// #Binary-Search

#include <iostream>
using namespace std;

typedef long long ll;
const ll MAXVAL = 1e12;

ll BinarySearch(ll x, ll y, ll k)
{
    ll l = 1, r = MAXVAL;
    while (l <= r) {
        ll mid = (l + r) >> 1, remainCnt = mid;
        for (int i = 0; i < x; i++)
            remainCnt -= remainCnt / y;
        if (remainCnt < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

ll Solve(ll x, ll y, ll k)
{
    ll ans = BinarySearch(x, y, k);
    if (ans > MAXVAL)
        ans = -1;
    return ans;
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