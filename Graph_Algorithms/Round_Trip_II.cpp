#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> vis(n + 1);
    vector<int> path;
    set<int> S;
    auto dfs = [&](int v, auto&& dfs) -> void {
        if (S.count(v)) {
            int i = 0;
            for (; path[i] != v; i++);
            cout << path.size() - i + 1 << "\n";
            for (; i < path.size(); i++)
                cout << path[i] << " ";
            cout << v << "\n";
            exit(0);
        }
        if (vis[v]) return;
        vis[v] = 1;
        S.insert(v);
        path.push_back(v);
        for (int u: adj[v])
            dfs(u, dfs);
        S.erase(v);
        path.pop_back();
    };
    for (int v = 1; v <= n; v++)
        if (!vis[v]) dfs(v, dfs);
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
