// #Math

#include <iostream>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;
int a[MAXN], bkt[MAXM], ans[MAXN];

void Solve(int n)
{
    int maxValue = 1;
    for (int i = 1; i <= n; i++) {
        maxValue = max(maxValue, a[i]);
        
        for (int j = 1; j * j <= a[i]; j++)
            if (a[i] % j == 0) {
                bkt[j]++;
                if (j * j != a[i])
                    bkt[a[i] / j]++;
            }
    }

    for (int i = 1; i <= maxValue; i++)
        ans[bkt[i]] = i;

    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Solve(n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}