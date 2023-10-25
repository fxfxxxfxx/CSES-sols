#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<int> cnt(n + 1);
    priority_queue<pair<int64_t,int>> PQ; // -cost, node
    PQ.push({0, 1});

    while (!PQ.empty()) {
        auto [ncost, node] = PQ.top();
        PQ.pop();
        auto cost = -ncost;
        if (cnt[node] == k)
            continue;
        cnt[node] += 1;
        if (node == n) {
            cout << cost << " ";
            if (cnt[node] == k) {
                cout << "\n";
                return;
            }
        }
        for (auto [nxt, c]: adj[node]) {
            auto new_cost = cost + c;
            if (cnt[nxt] == k)
                continue;
            PQ.push({-new_cost, nxt});
        }
    }
    abort();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
