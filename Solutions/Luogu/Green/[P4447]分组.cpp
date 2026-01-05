// #Greedy #Queue

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

void UpdateAns(int &ans, queue<int> &que, int curIdx)
{
    int beginIdx = que.front();
    que.pop();
    ans = min(ans, curIdx - beginIdx + 1);
}

int Solve(int n)
{
    sort(a + 1, a + n + 1);
    queue<int> que;

    int ans = n, cnt = 0, curIdx = 1;
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (i == n || a[i] != a[i + 1]) {
            while (que.size() < cnt)
                que.push(curIdx);
            while (que.size() > cnt)
                UpdateAns(ans, que, curIdx - 1);

            if (i == n || a[i] != a[i + 1] - 1) 
                while (!que.empty())
                    UpdateAns(ans, que, curIdx);
            
            cnt = 0, curIdx++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = Solve(n);
    cout << ans << endl;
}