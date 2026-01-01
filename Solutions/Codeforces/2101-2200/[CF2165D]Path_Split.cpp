// #Greedy

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN];
set<int> pos[MAXN * 2];

int Solve(int n)
{
    for (int i = 1; i <= 2 * n + 1; i++)
        pos[i].clear();
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back(make_pair(a[i], i));
        pos[a[i]].insert(i);
    }
    sort(vec.begin(), vec.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.first < y.first || (x.first == y.first && x.second > y.second);
    });
    
    int ans = n;
    for (int i = 0; i < n; i++) {
        int val = vec[i].first, idx = vec[i].second;
        auto iter = pos[val - 1].lower_bound(idx);
        if (iter != pos[val - 1].end())
            pos[val - 1].erase(iter), ans--;
        else {
            iter = pos[val + 1].lower_bound(idx);
            if (iter != pos[val + 1].end())
                pos[val + 1].erase(iter), ans--;
        }
    }
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = Solve(n);
        cout << ans << endl;
    }
}