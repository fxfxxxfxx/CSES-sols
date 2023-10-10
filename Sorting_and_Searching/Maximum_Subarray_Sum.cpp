#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    int64_t ans = -1e9, minsum = 0, nowsum = 0;
    for (int i = 0; i < n; i++) {
        int64_t p;
        cin >> p;

        nowsum += p;

        ans = max(ans, nowsum - minsum);
        minsum = min(minsum, nowsum);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
