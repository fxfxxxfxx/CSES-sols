#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m; cin >> n >> m;
    vector<array<int,3>> E(m);
    for (int i = 0; i < m; i++) {
        auto& [a, b, c] = E[i];
        cin >> a >> b >> c;
    }
    vector<int64_t> dis(n + 1);
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);

    for (int i = 0; i < n - 1; i++) {
        for (auto [a, b, c]: E) {
            if (dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
                p[b] = a;
            }
        }
    }
    for (auto [a, b, c]: E) {
        if (dis[a] + c < dis[b]) {
            cout << "YES\n";
            vector<int> ans{b};
            set<int> S{b};
            int node = a;
            while (!S.count(node)) {
                S.insert(node);
                ans.push_back(node);
                node = p[node];
            }
            cout << node;
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << " " << ans[i];
                if (ans[i] == node)
                    break;
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
