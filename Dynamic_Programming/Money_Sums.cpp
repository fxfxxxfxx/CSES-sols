#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    bitset<101001> B;
    B.set(0);
    for (int x: X)
        B |= B << x;
    cout << B.count() - 1 << "\n"; // don't count 0
    for (int v = 1; v <= 100000; v++)
        if (B.test(v)) cout << v << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
