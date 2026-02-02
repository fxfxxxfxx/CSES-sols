#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> P(n);
    for (int& p : P) cin >> p;
    int res = 0;
    for (int i = 1; i < n; i += 2)
        res ^= P[i];
    cout << (res == 0 ? "second\n" : "first\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
