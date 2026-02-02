#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    int mx = -1;
    vector<int> V(n);
    for (int &x : V) {
        cin >> x;
        mx = max(mx, x);
    }

    vector<int> P(mx + 1);
    iota(P.begin(), P.end(), 0);

    for (int p = 2; p <= mx; p++) {
        if (P[p] < p) continue;
        for (int64_t y = int64_t(p)*p; y <= mx; y += p)
            P[y] = p;
    }

    for (int v : V) {
        int x = v;
        map<int, int> M;
        while (x > 1) {
            M[P[x]] += 1;
            x /= P[x];
        }
        int64_t cnt = 1;
        for (auto [p, k] : M)
            cnt *= (k + 1);
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
