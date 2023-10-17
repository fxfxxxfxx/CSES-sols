#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    constexpr int mod = 1e9 + 7;

    vector<pair<int,int>> V;
    auto dfs = [&](int level, int pre, int now, auto&& dfs) -> void {
        if (level == n) {
            int mask = (1 << n) - 1;
            V.emplace_back(~pre & mask, now);
            return;
        }
        dfs(level + 1, pre, now, dfs);
        dfs(level + 1, pre | (1 << level), now | (1 << level), dfs);
        if (level == 0 || now & (1 << (level - 1)))
            return;
        dfs(level + 1, pre, now | (1 << level) | (1 << (level - 1)), dfs);
    };
    dfs(0, 0, 0, dfs);

    int pown = 1 << n;
    vector<int> dp(pown);
    dp.back() = 1;

    for (int i = 0; i < m; i++) {
        vector<int> curr(pown);
        for (auto [pre, now]: V)
            curr[now] = (curr[now] + dp[pre]) % mod;
        dp = curr;
    }
    cout << dp.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
