#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    if (n == 1) { cout << "01\n"; return; }

    int m = 1 << (n - 1);
    vector<array<int, 2>> adj(m);
    for (int i = 0; i < m; i++) {
        int a = (i << 1) & (m - 1);
        int b = a + 1;
        adj[i] = {a, b};
    }

    string ans;
    auto dfs = [&](int v, auto &&dfs) -> void {
        for (int i = 0; i < 2; i++) {
            if (adj[v][i] != -1) {
                int u = adj[v][i];
                adj[v][i] = -1;
                dfs(u, dfs);
            }
        }
        ans += "01"[v & 1];
    };
    dfs(0, dfs);
    ans += ans.substr(1, n-2);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
