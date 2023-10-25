#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a -= 1; b -= 1;
        adj[a].push_back(b);
    }

    int cnt = 0;
    vector<int> M(n, -1);
    auto dfs = [&](int v, auto&& dfs) -> int {
        if (M[v] != -1)
            return M[v];
        M[v] = cnt;
        cnt += 1;
        int mn = M[v];
        for (auto u: adj[v])
            mn = min(mn, dfs(u, dfs));
        if (v == 0)
            return 0;
        if (mn < M[v])
            return mn;
        cout << "NO\n" << v + 1 << " " << 1 << "\n";
        exit(0);
    };
    dfs(0, dfs);
    for (int i = 0; i < n; i++)
        if (M[i] == -1) {
            cout << "NO\n" << 1 << " " << i + 1 << "\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
