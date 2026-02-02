#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    double memory[607] = {};
    double *dp = memory + 6;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int v = 6 * n; v >= 0; v--)
            dp[v] = (dp[v-1] + dp[v-2] + dp[v-3] + dp[v-4] + dp[v-5] + dp[v-6]) / 6.0;
    double ans = 0;
    for (int i = a; i <= b; i++)
        ans += dp[i];
    cout << fixed << setprecision(6) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
