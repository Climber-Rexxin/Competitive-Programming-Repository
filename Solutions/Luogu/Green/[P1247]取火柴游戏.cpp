// #Game-Theory

#include <iostream>
using namespace std;

const int MAXN = 5e5 + 5;
int a[MAXN];

void Solve(int n)
{
    int xorSum = 0;
    for (int i = 1; i <= n; i++)
        xorSum ^= a[i];
    
    if (xorSum == 0) {
        cout << "lose" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
        if (a[i] >= (xorSum ^ a[i])) {
            int decrease = a[i] - (xorSum ^ a[i]);
            cout << decrease << " " << i << endl;
            a[i] -= decrease;
            break;
        }

    for (int i = 1; i <= n; i++)
        cout << a[i] << (i == n ? '\n' : ' ');
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Solve(n);
}