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

    auto dfs = [&](int p, int v, auto&& dfs) -> pair<int, int> {
        int fmax = -1, smax = -1, imax = -1;

        for (int u : adj[v]) {
            if (u == p) continue;
            auto [u_self, u_root] = dfs(v, u, dfs);

            imax = max(imax, u_self);
            if (u_root > smax) swap(smax, u_root);
            if (smax > fmax) swap(smax, fmax);
        }

        return {max(imax, fmax + smax + 2), fmax + 1};
    };

    auto [ans, _] = dfs(1, 1, dfs);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
