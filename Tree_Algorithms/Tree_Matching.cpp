#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dfs = [&](int p, int v, auto&& dfs) -> pair<int,int> {
        int min_loss = n + n;
        int tot_pick = 0;
        bool is_leaf = true;
        for (int u : adj[v]) {
            if (u == p) continue;
            is_leaf = false;
            auto [u_pick, u_nopick] = dfs(v, u, dfs);
            min_loss = min(min_loss, u_pick - u_nopick);
            tot_pick += u_pick;
        }
        if (is_leaf) return {0, 0};
        int v_pick = 1 + tot_pick - min_loss;
        int v_nopick = tot_pick;
        return {v_pick, v_nopick};
    };
    auto [pick, nopick] = dfs(1, 1, dfs);
    int ans = max(pick, nopick);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
