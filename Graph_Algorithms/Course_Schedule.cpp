#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<int> cnt(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        cnt[b] += 1;
    }
    queue<int> Q;
    vector<int> ans;
    for (int v = 1; v <= n; v++)
        if (!cnt[v]) Q.push(v);
    while (!Q.empty()) {
        auto v = Q.front();
        Q.pop();
        ans.push_back(v);
        for (int u: adj[v]) {
            cnt[u] -= 1;
            if (!cnt[u])
                Q.push(u);
        }
    }
    if (ans.size() < n)
        cout << "IMPOSSIBLE";
    else for (int v: ans)
        cout << v << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
