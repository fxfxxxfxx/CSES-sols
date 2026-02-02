#include <bits/stdc++.h>

using namespace std;

static constexpr int M = 1000000007;
static constexpr int PHI_M = M - 1;

static int64_t comp(int64_t a, int64_t b, int64_t M) {
    int64_t mul = a, ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * mul) % M;
        mul = (mul * mul) % M;
        b >>= 1;
    }
    return ans;
}

static void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t a, b, c; cin >> a >> b >> c;
        int64_t ans = comp(a, comp(b, c, PHI_M), M);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
