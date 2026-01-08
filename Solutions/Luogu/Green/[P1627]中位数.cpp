// #Combinatorics

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN];
unordered_map<int, int> mp[2];

ll Solve(int n, int b)
{
    int tag = 0, cntSum = 0, pos;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b) {
            found = true;
            pos = i;
        }
        if (!found)
            continue;

        if (a[i] != b)
            a[i] < b ? cntSum++ : cntSum--;
        tag = !tag;
        mp[tag][cntSum]++;
    }

    tag = cntSum = 0;
    ll ans = 0;
    for (int i = pos; i >= 1; i--) {
        if (a[i] != b)
            a[i] < b ? cntSum-- : cntSum++;
        tag = !tag;
        ans += mp[tag][cntSum];
    }
    return ans;
}

int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = Solve(n, b);
    cout << ans << endl;
}