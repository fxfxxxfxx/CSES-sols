#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1e6 + 1;

static void solve() {
    int n;
    cin >> n;
    vector<int> dp(n+1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t) {
            dp[i] = min(dp[i], dp[i - (t % 10)] + 1);
            t /= 10;
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
