#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    const int inf = x+1;
    vector<int> dp(x+1, inf);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int c: coins)
            dp[i] = min(dp[i], i >= c ? dp[i-c] + 1 : inf);
    }
    cout << (dp[x] >= inf ? -1 : dp[x]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
