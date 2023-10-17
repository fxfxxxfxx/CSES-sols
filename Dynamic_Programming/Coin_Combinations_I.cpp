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

    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int coin: coins) {
            if (i >= coin)
                dp[i] = (dp[i] + dp[i - coin]) % mod;
        }
    }
    cout << dp[x] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
