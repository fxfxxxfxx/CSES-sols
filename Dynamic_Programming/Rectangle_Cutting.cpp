#include <bits/stdc++.h>

using namespace std;

static int dp[501][501];
int _ = [] {
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++) {
            if (i == j) continue;
            dp[i][j] = 1e9;
            for (int ii = 1; ii < i; ii++)
                dp[i][j] = min(dp[i][j], dp[ii][j] + dp[i - ii][j] + 1);
            for (int jj = 1; jj < j; jj++)
                dp[i][j] = min(dp[i][j], dp[i][jj] + dp[i][j - jj] + 1);
        }
    return 0;
}();

static void solve() {
    int a, b; cin >> a >> b;
    cout << dp[a][b] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
