#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, k; cin >> n >> k;
    vector<int> P(k);
    for (int& p : P) cin >> p;
    vector<int8_t> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int p : P) {
            if (i - p < 0) continue;
            dp[i] |= ~(dp[i-p]);
        }
    }
    string s;
    for (int i = 1; i <= n; i++)
        s.push_back(dp[i] ? 'W' : 'L');
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
