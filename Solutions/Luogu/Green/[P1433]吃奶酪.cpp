// #Search #Bitmask-DP

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAXN = 1 << 15;
double x[MAXN], y[MAXN], dp[15][MAXN];

double GetDist(int a, int b)
{
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

double Dfs(int pos, int bitmask, int n)
{
    if (bitmask == (1 << n) - 1)
        return 0;
    
    double &ref = dp[pos][bitmask];
    if (ref != 0)
        return ref;

    double ans = 1e10;
    for (int i = 0; i < n; i++) {
        if (bitmask & (1 << i))
            continue;
        
        double remainDist = GetDist(pos, i) + Dfs(i, bitmask | (1 << i), n);
        ans = min(ans, remainDist);
    }
    ref = ans;
    return ans;
}

double Solve(int n)
{
    double ans = 1e10;
    for (int i = 0; i < n; i++) {
        double dist = sqrt(x[i] * x[i] + y[i] * y[i]);
        ans = min(ans, dist + Dfs(i, 1 << i, n));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    double ans = Solve(n);
    cout << fixed << setprecision(2) << ans << endl;
}