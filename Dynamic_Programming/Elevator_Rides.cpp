#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<int> W(n);
    for (int& w: W) cin >> w;

    vector<int> V[21];
    for (int i = 0; i < (1 << n); i++)
        V[__builtin_popcount(i)].push_back(i);

    using T = pair<int, int>;
    vector<T> dp(1 << n, {21, 0});
    dp[0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        for (int b: V[i]) {
            for (int j = 0; j < n; j++) {
                if (!(b & (1 << j))) continue;
                T v = dp[b ^ (1 << j)];
                v.second += W[j];
                if (v.second > x)
                    v = {v.first + 1, W[j]};
                dp[b] = min(dp[b], v);
            }
        }
    }

    cout << dp[(1 << n) - 1].first + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
