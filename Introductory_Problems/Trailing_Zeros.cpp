#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        n /= 5;
        ans += n;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
