#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, q; cin >> n >> q;
    vector V(30, vector<int>(n + 1));
    for (int t = 1; t <= n; t++)
        cin >> V[0][t];
    for (int s = 1; s < 30; s++)
        for (int t = 1; t <= n; t++)
            V[s][t] = V[s-1][V[s-1][t]];
    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int lay = 0;
        while (k) {
            if (k & 1)
                x = V[lay][x];
            lay += 1;
            k >>= 1;
        }
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
