#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    constexpr int mod = 1e9 + 7;
    vector<int> res(n + 1, -1);
    res[n] = 1;
    auto dfs = [&](int v, auto&& dfs) -> void {
        if (res[v] != -1) return;
        res[v] = 0;
        for (int u: adj[v]) {
            dfs(u, dfs);
            res[v] = (res[v] + res[u]) % mod;
        }
    };
    dfs(1, dfs);
    cout << res[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
