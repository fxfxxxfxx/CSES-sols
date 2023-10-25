#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<pair<int,int>> res(n + 1);
    res[n] = {1, -1};

    auto dfs = [&](int v, auto&& dfs) -> void {
        if (res[v].first) return;
        res[v] = {-1, -1};
        int mx = -1, mxu = -1;
        for (int u: adj[v]) {
            dfs(u, dfs);
            auto [scu, _] = res[u];
            if (scu > mx) {
                mx = scu;
                mxu = u;
            }
        }
        if (mx != -1)
            res[v] = {mx + 1, mxu};
    };
    dfs(1, dfs);
    if (res[1].first == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << res[1].first << "\n";
    int now = 1;
    for (int i = 0; i < res[1].first; i++) {
        cout << now << " ";
        now = res[now].second;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
