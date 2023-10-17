#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    vector<vector<int64_t>> dp(n, vector<int64_t>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = X[i];
    for (int diff = 1; diff < n; diff++) {
        for (int left = 0; left + diff < n; left++) {
            int right = left + diff;
            dp[left][right] = max(X[left] - dp[left + 1][right], X[right] - dp[left][right - 1]);
        }
    }
    cout << (dp[0][n - 1] + accumulate(X.begin(), X.end(), int64_t(0))) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
