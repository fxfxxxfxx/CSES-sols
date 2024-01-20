#include <bits/stdc++.h>

using namespace std;

[[noreturn]] static void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

static void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a -= 1; b -= 1;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (auto &A : adj)
        if (A.size() & 1) fail();

    vector<int> ans;
    auto dfs = [&](int v, auto &&dfs) -> void {
        while (!adj[v].empty()) {
            int u = *adj[v].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            dfs(u, dfs);
        }
        ans.push_back(v);
    };
    dfs(0, dfs);

    if (ans.size() < m + 1) fail();

    for (int i = 0; i <= m; i++)
        cout << ans[i]+1 << " \n"[i==m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
