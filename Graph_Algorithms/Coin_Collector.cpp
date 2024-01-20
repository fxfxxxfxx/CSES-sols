#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<int64_t> K(n);
    for (int64_t &k : K) cin >> k;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
    }

    vector<int64_t> parent(n), coin(n);
    vector<int> onstack(n), low(n), dfn(n);
    vector<int> stack, rev_topo;
    int index = 1;

    auto dfs = [&](int v, auto &&dfs) -> void {
        dfn[v] = low[v] = index;
        index += 1;

        onstack[v] = 1;
        stack.push_back(v);

        for (int u: adj[v]) {
            if (!dfn[u]) dfs(u, dfs);
            if (onstack[u])
                low[v] = min(low[v], low[u]);
        }

        if (dfn[v] == low[v]) {
            int u = -1;
            do {
                u = stack.back();
                onstack[u] = 0;
                parent[u] = v;
                coin[v] += K[u];
                stack.pop_back();
            } while (u != v);
            rev_topo.push_back(v);
        }
    };
    for (int v = 0; v < n; v++)
        if (!dfn[v]) dfs(v, dfs);

    vector<vector<int>> nadj(n);
    for (int v = 0; v < n; v++) {
        int pv = parent[v];
        for (int u : adj[v]) {
            int pu = parent[u];
            if (pv == pu) continue;
            nadj[pv].push_back(pu);
        }
    }

    int64_t ans = 0;
    vector<int64_t> dp(n);
    for (int v : rev_topo) {
        int64_t mx = 0;
        for (int u : nadj[v])
            mx = max(mx, dp[u]);
        dp[v] = coin[v] + mx;
        ans = max(ans, dp[v]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
