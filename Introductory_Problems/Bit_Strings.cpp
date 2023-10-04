#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1000000000 + 7;

static void solve() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans << 1) % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
