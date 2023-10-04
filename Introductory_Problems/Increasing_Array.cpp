#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n;
    cin >> n;

    int pre;
    cin >> pre;
    
    uint64_t ans = 0;
    for (int i = 1; i < n; i++) {
        int m;
        cin >> m;
        ans += m < pre ? pre - m : 0;
        pre = m > pre ? m : pre;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
