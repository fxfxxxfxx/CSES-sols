#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int M = 1000000007;
    int64_t n; cin >> n;

    int ans = 0;
    for (int64_t i = 1; n / i > i; i++)
        ans = (ans + n / i * i) % M;

    for (int64_t i = 1; i * i <= n; i++) {
        // n // x = i
        // x : (n/(i+1), n/i]
        // x : [n/(i+1)+1, n/i]
        int64_t a = n / (i+1) % M, b = n / i % M;
        int64_t sm = (a + b + 1) * (b - a) / 2 % M;
        ans = (ans + sm * i) % M;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
