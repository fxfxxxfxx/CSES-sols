#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m, q; cin >> n >> m >> q;

    constexpr int64_t inf = 1e16;
    vector<vector<int64_t>> dis(n + 1, vector<int64_t>(n + 1, inf));

    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for (int v = 1; v <= n; v++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                dis[a][b] = min(dis[a][b], dis[a][v] + dis[v][b]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << (dis[a][b] == inf ? -1 : dis[a][b]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
