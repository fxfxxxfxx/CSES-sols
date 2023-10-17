#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int mod = 1e9 + 7;

    int n; cin >> n;
    int total = n * (n + 1) / 2;
    if (total & 1) {
        cout << "0\n";
        return;
    }
    int need = total / 2;
    vector<int> dp(need + 1);
    dp[1] = 1;
    for (int v = 2; v <= n; v++)
        for (int a = need; a - v >= 0; a--)
            dp[a] = (dp[a] + dp[a - v]) % mod;
    cout << dp[need] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
