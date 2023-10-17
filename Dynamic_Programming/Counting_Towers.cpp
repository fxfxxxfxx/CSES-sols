#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int mod = 1e9 + 7;
    int t; cin >> t;
    vector<int64_t> dp(1000001);
    dp[0] = 1;
    dp[1] = 2;
    int64_t sm = 3;
    for (int v = 2; v <= 1000000; v++) {
        dp[v] = (dp[v-1] * 7 - sm * 2) % mod;
        dp[v] = (dp[v] + mod) % mod;
        sm = (sm + dp[v]) % mod;
    }
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
