#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (int& x : X) cin >> x;

    map<int, int> prev_add_1;
    int64_t ans = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
        int x = X[i];
        left = max(left, prev_add_1[x]);
        prev_add_1[x] = i + 1;
        ans += i - left + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
