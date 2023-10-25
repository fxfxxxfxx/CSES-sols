#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> aadj(n + 1), radj(n + 1);
    vector<array<int, 3>> E(m);
    for (auto& [a, b, x]: E) {
        cin >> a >> b >> x;
        aadj[a].push_back(b);
        radj[b].push_back(a);
    }
    auto dfs = [](int v, auto& adj, auto& vis, auto&& dfs) -> void {
        if (vis[v]) return;
        vis[v] = 1;
        for (int u: adj[v])
            dfs(u, adj, vis, dfs);
    };
    vector<int> vvis(n + 1), rvis(n + 1);
    dfs(1, aadj, vvis, dfs);
    dfs(n, radj, rvis, dfs);

    vector<array<int, 3>> EE;
    for (auto [a, b, x]: E) {
        if (!vvis[a] || !rvis[b]) continue;
        EE.push_back({a, b, x});
    }

    vector<int64_t> score(n + 1, -1e17);
    score[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [a, b, x]: EE)
            score[b] = max(score[b], score[a] + x);
    }
    for (auto [a, b, x]: EE)
        if (score[a] + x > score[b]) {
            cout << "-1\n";
            return;
        }
    cout << score[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
