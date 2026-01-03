#include <iostream>
#include <string>
using namespace std;

int Solve(const string &s) {
    bool leftEnd = false, rightBegin = false;
    int leftCnt = 0, starCnt = 0, rightCnt = 0;
    for (char ch : s) {
        if (ch == '<') {
            if (leftEnd)
                return -1;
            leftCnt++;
        } else if (ch == '*') {
            if (rightBegin || starCnt > 0)
                return -1;
            leftEnd = true;
            starCnt++;
        } else {
            leftEnd = rightBegin = true;
            rightCnt++;
        }
    }
    return max(leftCnt, rightCnt) + starCnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = Solve(s);
        cout << ans << endl;
    }
}
