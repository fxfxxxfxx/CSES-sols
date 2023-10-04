#include <bits/stdc++.h>

using namespace std;

static void solve() {
    string s;
    cin >> s;
    
    char pre = '^';
    int cnt = 0, ans = 0;
    for (char c: s) {
        if (pre == c) {
            cnt++;
        } else {
            pre = c;
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
