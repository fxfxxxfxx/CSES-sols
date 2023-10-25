#include <bits/stdc++.h>

using namespace std;

struct Data {
    int64_t dis = 1e18;
    int count = 0;
    int minn = 1e9;
    int maxn = -1;
};

static void solve() {
    constexpr int mod = 1e9 + 7;
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<Data> V(n + 1);
    priority_queue<tuple<int64_t,int,int>> PQ; // -cost, from, to
    V[1] = {0, 1, 0, 0};
    for (auto [u, c]: adj[1])
        PQ.emplace(-c, 1, u);
    while (!PQ.empty()) {
        auto [ncost, from, to] = PQ.top(); PQ.pop();
        auto cost = -ncost;
        if (cost > V[to].dis) continue;
        if (cost == V[to].dis) {
            V[to].count = (V[to].count + V[from].count) % mod;
            V[to].minn = min(V[to].minn, V[from].minn + 1);
            V[to].maxn = max(V[to].maxn, V[from].maxn + 1);
            continue;
        }
        V[to] = {cost, V[from].count, V[from].minn + 1, V[from].maxn + 1};
        for (auto [u, c]: adj[to]) {
            auto nxt = cost + c;
            PQ.emplace(-nxt, to, u);
        }
    }
    auto [a, b, c, d] = V[n];
    cout << a << " " << b << " " << c << " " << d << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
