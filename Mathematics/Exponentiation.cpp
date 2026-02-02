#include <bits/stdc++.h>

using namespace std;

static void comp(void) {
    constexpr int M = 1000000007;
    int64_t a, b; cin >> a >> b;

    int64_t mul = a, ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * mul) % M;
        mul = (mul * mul) % M;
        b >>= 1;
    }
    cout << ans << "\n";
}

static void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        comp();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
