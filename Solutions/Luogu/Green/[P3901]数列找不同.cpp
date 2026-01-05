// #Two-Pointers

#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], leftBegin[MAXN], bkt[MAXN];

void Solve(int n, int q)
{
    int leftPtr = 1;
    for (int i = 1; i <= n; i++) {
        while (bkt[a[i]])
            bkt[a[leftPtr++]]--;
        bkt[a[i]]++;
        leftBegin[i] = leftPtr;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (l >= leftBegin[r] ? "Yes" : "No") << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Solve(n, q);
}