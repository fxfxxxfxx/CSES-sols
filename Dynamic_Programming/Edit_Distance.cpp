#include <bits/stdc++.h>

using namespace std;

static int dp[5001][5001];

static void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i+1][j+1] = min({dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i][j] + (s[i] != t[j])});
    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
