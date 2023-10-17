#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int mod = 1e9 + 7;
    int n, m; cin >> n >> m;
    vector<int> V(n);
    for (int& v: V) cin >> v;

    vector<int64_t> dp(m + 2);
    if (V[0] == 0)
        fill(dp.begin() + 1, dp.begin() + m + 1, 1);
    else dp[V[0]] = 1;

    for (int i = 1; i < V.size(); i++) {
        vector<int64_t> curr(m + 2);
        for (int j = 1; j <= m; j++) {
            if (V[i] != 0 && V[i] != j) continue;
            curr[j] = (dp[j-1] + dp[j] + dp[j+1]) % mod;
        }
        dp = curr;
    }
    int ans = 0;
    for (int v = 1; v <= m; v++)
        ans = (ans + dp[v]) % mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
