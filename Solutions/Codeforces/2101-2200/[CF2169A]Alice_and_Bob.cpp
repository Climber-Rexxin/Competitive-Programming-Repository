#include <iostream>
using namespace std;

const int MAXN = 3e5 + 5;
int v[MAXN];

int Solve(int n, int a)
{
    int lessCnt = 0, greaterCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] < a)
            lessCnt++;
        if (v[i] > a)
            greaterCnt++;
    }
    return lessCnt >= greaterCnt ? a - 1 : a + 1;
}

int main()
{
    int t, n, a;
    cin >> t;
    while (t--) {
        cin >> n >> a;
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        int ans = Solve(n, a);
        cout << ans << endl;
    }
}