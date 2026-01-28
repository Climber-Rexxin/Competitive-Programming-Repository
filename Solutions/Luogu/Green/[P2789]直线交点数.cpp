// #Math #DP

#include <iostream>
#include <set>
using namespace std;

set<int> dp[26];
int Solve(int n)
{
    dp[0].insert(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            int cnt = j * (i - j);
            for (int x : dp[i - j])
                dp[i].insert(x + cnt);
        }
    return dp[n].size();
}

int main()
{
    int n;
    cin >> n;
    int ans = Solve(n);
    cout << ans << endl;
}