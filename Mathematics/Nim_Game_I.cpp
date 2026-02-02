#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (int& x : X) cin >> x;
    int res = 0;
    for (int x: X) res ^= x;
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
