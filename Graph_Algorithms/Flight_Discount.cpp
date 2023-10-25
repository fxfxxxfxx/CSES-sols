#include <bits/stdc++.h>

using namespace std;

static int64_t solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    priority_queue<array<int64_t, 3>> PQ; // {-cost, city, halfed}
    PQ.push({0, 1, 0});
    vector<int> vis0(n + 1), vis1(n + 1);

    while (!PQ.empty()) {
        auto [nc, v, halfed] = PQ.top();
        PQ.pop();
        auto& vis = halfed ? vis1 : vis0;
        if (vis[v]) continue;
        vis[v] = 1;
        if (halfed && v == n)
            return -nc;
        for (auto [u, c]: adj[v]) {
            PQ.push({nc - c, u, halfed});
            if (!halfed)
                PQ.push({nc - c / 2, u, 1});
        }
    }
    abort();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << solve() << "\n";
    return 0;
}
