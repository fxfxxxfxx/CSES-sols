#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<array<int, 3>> V(n);
    for (auto& [a, b, p]: V)
        cin >> a >> b >> p;
    map<int, int> M;
    for (auto [a, b, p]: V)
        M[a] = M[b] = 1;
    int cnt = 1;
    for (auto [k, _]: M)
        M[k] = cnt++;
    for (auto& [a, b, p]: V)
        a = M[a], b = M[b];
    sort(V.begin(), V.end(), [&](const auto& va, const auto& vb) {
        return va[1] < vb[1];
    });
    vector<int64_t> dp(2 * n + 1);
    int ptr = 0;
    for (int v = 1; v <= 2 * n; v++) {
        dp[v] = dp[v - 1];
        while (ptr < n && V[ptr][1] == v) {
            dp[v] = max(dp[v], V[ptr][2] + dp[V[ptr][0] - 1]);
            ptr += 1;
        }
    }
    cout << dp[2 * n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
