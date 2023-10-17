#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    const int mod = 1e9 + 7;

    // dp[i][j] = #ways to produce $j with coins[:i]
    // dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
    // O(nx) = O(nx)
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i] = vector<int>(x + 1);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
                dp[i][j] = (dp[i][j] + dp[i][j-coins[i-1]]) % mod;
        }
    }
    cout << dp[n][x] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
