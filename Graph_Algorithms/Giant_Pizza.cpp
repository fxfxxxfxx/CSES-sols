#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
        string s1, s2; int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;
        x1 = x1 * (s1 == "+" ? 1 : -1);
        x2 = x2 * (s2 == "+" ? 1 : -1);
        adj[-x1].push_back(x2);
        adj[-x2].push_back(x1);
    }

    map<int, int> SCC, low, dfn;

    set<int> onstack;
    vector<int> stack;
    int index = 1, scc = 1;

    const auto dfs = [&](int v, auto &&dfs) -> void {
        dfn[v] = index;
        index += 1;

        low[v] = dfn[v];
        onstack.insert(v);
        stack.push_back(v);

        for (auto u: adj[v]) {
            if (!dfn[u])
                dfs(u, dfs);
            if (onstack.count(u))
                low[v] = min(low[v], low[u]);
        }

        if (dfn[v] == low[v]) {
            int u = -1;
            do {
                u = stack.back();
                onstack.erase(u);
                SCC[u] = scc;
                stack.pop_back();
            } while (u != v);
            scc += 1;
        }
    };

    for (int v = 1; v <= m; v++) {
        if (!dfn[v]) dfs(v, dfs);
        if (!dfn[-v]) dfs(-v, dfs);
    }

    string ans;
    for (int i = 1; i <= m; i++) {
        if (SCC[i] == SCC[-i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans += SCC[i] < SCC[-i] ? "+ " : "- ";
    }
    ans.pop_back();
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
