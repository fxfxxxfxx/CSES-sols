#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<int> order;
    vector<int> vis(n);
    auto dfs = [&](int v, auto &&dfs) -> void {
        vis[v] = 1;
        for (auto u: adj[v]) {
            if (vis[u]) continue;
            dfs(u, dfs);
        }
        order.push_back(v);
    };
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i, dfs);

    reverse(order.begin(), order.end());
    
    vector<int> label(n);
    auto dfs2 = [&](int v, int index, auto &&dfs2) -> void {
        label[v] = index;
        for (auto u: radj[v]) {
            if (label[u]) continue;
            dfs2(u, index, dfs2);
        }
    };

    int index = 1;
    for (auto v: order) {
        if (label[v]) continue;
        dfs2(v, index, dfs2);
        index += 1;
    }
    cout << index - 1 << "\n";
    for (auto b: label)
        cout << b << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
