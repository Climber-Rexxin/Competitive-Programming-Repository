// #Greedy

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 5e5 + 5;
int a[MAXN];

int Query(int c, int n)
{
    priority_queue<int> heap;
    for (int i = 1; i <= min(n, 30); i++)
        heap.push(a[i]);
    
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int bit = 1 << i;
        if (c < bit)
            continue;
            
        int maxVal = heap.top();
        heap.pop();
        if (maxVal >= bit)
            heap.push(maxVal - bit);
        else {
            ans += bit - maxVal;
            if (heap.empty())
                heap.push(0);
        }
        c -= bit;
    }
    return ans;
}

void Solve(int n, int q)
{
    sort(a + 1, a + n + 1, greater<int>());

    while (q--) {
        int c;
        cin >> c;
        int ans = Query(c, n);
        cout << ans << endl;
    }
}

int main()
{
    int t, n, q;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Solve(n, q);
    }
}