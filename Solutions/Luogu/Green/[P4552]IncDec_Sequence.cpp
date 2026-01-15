// #Thinking

#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN];

pair<ll, ll> Solve(int n)
{
    ll posDifSum = 0, negDifSum = 0;
    for (int i = 2; i <= n; i++) {
        int dif = a[i] - a[i - 1];
        if (dif > 0)
            posDifSum += dif;
        else
            negDifSum -= dif;
    }

    ll ans1 = max(posDifSum, negDifSum);
    ll ans2 = abs(posDifSum - negDifSum) + 1;
    return make_pair(ans1, ans2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto ans = Solve(n);
    cout << ans.first << endl << ans.second << endl;
}