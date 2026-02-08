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

    vector<int> maxdep(n + 1);
    auto getdep = [&](int p, int v, auto&& getdep) -> int {
        for (int u : adj[v]) {
            if (u == p) continue;
            maxdep[v] = max(maxdep[v], 1 + getdep(v, u, getdep));
        }
        return maxdep[v];
    };
    getdep(1, 1, getdep);

    vector<int> maxdis(n + 1);
    auto getdis = [&](int p, int v, int carry, auto&& getdis) -> void {
        int first = 0, second = 0;
        for (int u : adj[v]) {
            if (u == p) continue;
            int u_dep = maxdep[u] + 1;
            if (u_dep > second) swap(u_dep, second);
            if (second > first) swap(second, first);
        }

        for (int u : adj[v]) {
            if (u == p) continue;
            int u_dep = maxdep[u] + 1;
            int u_down = u_dep == first ? second : first;
            getdis(v, u, 1 + max(carry, u_down), getdis);
        }
        maxdis[v] = max(carry, first);
    };
    getdis(1, 1, 0, getdis);

    for (int v = 1; v <= n; v++)
        cout << maxdis[v] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
