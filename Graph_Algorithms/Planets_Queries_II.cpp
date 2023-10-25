#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, q; cin >> n >> q;

    vector<vector<int>> T(18, vector<int>(n));
    for (auto& t: T[0]) {
        cin >> t;
        t -= 1;
    }

    for (int i = 1; i < 18; i++)
        for (int v = 0; v < n; v++)
            T[i][v] = T[i-1][T[i-1][v]];

    vector<array<int, 4>> D(n, {-1, -1, -1, -1}); // dis, endv, index, len

    for (int v = 0; v < n; v++) {
        if (D[v][0] != -1) continue;

        set<int> P;
        vector<int> path;
        int vv = v;
        while (D[vv][0] == -1 && !P.count(vv)) {
            path.push_back(vv);
            P.insert(vv);
            vv = T[0][vv];
        }
        if (D[vv][0] != -1) {
            int dis = D[vv][0];
            for (int k = path.size() - 1; k >= 0; k--) {
                dis += 1;
                D[path[k]] = D[vv];
                D[path[k]][0] = dis;
            }
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (path[i] != vv) continue;
                int len = path.size() - i;
                for (int j = 0; j < i; j++)
                    D[path[j]] = {i - j, path[i], 0, len};
                for (int j = i; j < path.size(); j++)
                    D[path[j]] = {0, path[i], j - i, len};
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a -= 1; b -= 1;

        auto [da, enda, ia, lena] = D[a];
        auto [db, endb, ib, lenb] = D[b];
        if (lena != lenb || da < db) {
            cout << "-1\n";
            continue;
        }
        int ans = -1;
        if (db == 0) {
            ans = da + ((ib - ia + lena) % lena);
        } else {
            ans = da - db;
        }
        int ta = ans, v = a, k = 0;
        while (ta) {
            if (ta & 1)
                v = T[k][v];
            ta >>= 1;
            k += 1;
        }
        if (v == b) cout << ans << "\n";
        else cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
