#include <bits/stdc++.h>

using namespace std;

struct DirectedEulerianPath {
    vector<int> path;
    vector<set<int>> adj;

    DirectedEulerianPath(const vector<set<int>> adj) : adj{adj} { 
        dfs(0);
        reverse(path.begin(), path.end());
    }

    void dfs(int v) {
        while (!adj[v].empty()) {
            int u = *adj[v].begin();
            adj[v].erase(u);
            dfs(u);
        }
        path.push_back(v);
    }
};

[[noreturn]] static void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

static void solve() {
    int n, m; cin >> n >> m;

    vector<int> abs_deg(n);
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a -= 1; b -= 1;
        adj[a].insert(b);
        abs_deg[a] -= 1;
        abs_deg[b] += 1;
    }

    int one = -1, neg = -1;
    for (int i = 0; i < n; i++) {
        int v = abs_deg[i];
        if (v > 1 || v < -1) fail();
        if (v == 0) continue;
        if (v == 1) one = i;
        if (v == -1) neg = i;
    }
    if (one != n-1 || neg != 0) fail();

    DirectedEulerianPath EP(adj);

    if (EP.path.size() < size_t(m + 1))
        fail();

    for (int x: EP.path)
        cout << x+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
