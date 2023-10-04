#include <bits/stdc++.h>

using namespace std;

static void solve() {
    // 2 3 4 4 ... 4 3 2
    // 3 4 6 6 ... 6 4 3
    // 4 6 8 8 ... 8 6 4
    int n;
    cin >> n;

    int ans4[] = {-1, 0, 6, 28, 96};
    for (int i = 1; i <= 4 && i <= n; i++) {
        cout << ans4[i] << '\n';
    }

    uint64_t pre = 96;
    for (uint64_t i = 5; i <= n; i++) {
        uint64_t inc_valid = ((2 + 3) * 2 + 4 * (i - 4)) * 2 - 4;
        uint64_t inc_all = i * (i-1) * (2*i-1);
        uint64_t ans = pre + inc_all - inc_valid;
        cout << ans << '\n';
        pre = ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
