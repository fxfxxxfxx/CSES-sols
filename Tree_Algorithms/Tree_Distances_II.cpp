#include <bits/stdc++.h>
 
using namespace std;
 
static void solve() {
    int n; cin >> n;
    vector adj(n + 1, vector<int>{});
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    using T = pair<int, int64_t>;
    vector<T> V(n + 1); // n_path, sum_dis
    auto getdown = [&](int p, int v, auto&& getdown) -> T {
        int n_path = 1;
        int64_t sum_dis = 0;
        for (int u : adj[v]) {
            if (u == p) continue;
            auto [u_path, u_dis] = getdown(v, u, getdown);
            n_path += u_path;
            sum_dis += u_dis + u_path;
        }
        return (V[v] = {n_path, sum_dis});
    };
    getdown(1, 1, getdown);
 
    vector<int64_t> ans(n + 1);
    auto getres = [&](int p, int v, auto&& getres) -> void {
        if (v == 1) {
            ans[v] = V[v].second;
        } else {
            auto [v_path, v_dis] = V[v];
            ans[v] = ans[p] - v_path + (n - v_path);
        }
        for (int u : adj[v]) {
            if (u == p) continue;
            getres(v, u, getres);
        }
    };
    getres(1, 1, getres);
    for (int v = 1; v <= n; v++)
        cout << ans[v] << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
