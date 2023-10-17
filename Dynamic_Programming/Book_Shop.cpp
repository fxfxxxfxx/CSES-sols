#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> V(n);
    for (auto& [h, _]: V) cin >> h;
    for (auto& [_, s]: V) cin >> s;

    vector<int> dp(x + 1);
    for (auto [h, s]: V)
        for (int c = x; c >= 0; c--)
            if (c >= h) dp[c] = max(dp[c], dp[c-h] + s);
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
