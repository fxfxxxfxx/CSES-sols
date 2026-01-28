#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int mod = 1000000007;
    int n; cin >> n;
    vector<int> X(n);
    for (int &x : X) cin >> x;

    map<int, int> M;
    for (int x : X) M[x] += 1;

    int64_t res = 1;
    for (auto [val, cnt] : M)
        res = res * (cnt + 1) % mod;
    int ans = (res + (mod - 1)) % mod;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
