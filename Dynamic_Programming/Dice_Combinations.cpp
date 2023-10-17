#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

static void solve() {
    // dp[i] = dp[i-1] + ... + dp[i-6]
    // dp[i] = dp[i-1] + dp[i-1] - dp[i-7]
    int n;
    cin >> n;

    vector<int> dp {1, 1, 2, 4, 8, 16, 32};
    dp.resize(n + 1);

    for (int i = 7; i <= n; i++)
        dp[i] = ((dp[i-1] + dp[i-1]) % mod - dp[i-7]) % mod;
    
    int ans = (dp[n] + mod) % mod;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
