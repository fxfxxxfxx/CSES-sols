#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<int64_t> dis(n + 1, -1);
    priority_queue<pair<int64_t,int>, vector<pair<int64_t,int>>, greater<pair<int64_t,int>>> Q;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [cost, v] = Q.top();
        Q.pop();
        if (dis[v] != -1)
            continue;
        dis[v] = cost;
        for (auto [u, len]: adj[v]) {
            if (dis[u] != -1) continue;
            Q.push({cost + len, u});
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
