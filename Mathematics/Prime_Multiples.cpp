#include <bits/stdc++.h>

using namespace std;

static void solve() {
    uint64_t n; int k;
    cin >> n >> k;
    vector<uint64_t> M(1<<k);
    M[0] = 1;
    for (int i = 0; i < k; i++)
        cin >> M[1<<i];

    for (int bit = 1; bit < (1<<k); bit++) {
        int x = bit & (bit - 1);
        int y = bit ^ x;
        uint64_t a = M[x], b = M[y], c = a * b;
        if (a && c / a == b) M[bit] = c;
    }

    uint64_t ans = 0;
    for (int bit = 0; bit < (1<<k); bit++) {
        if (!M[bit]) continue;
        if (bitset<20>(bit).count() & 1)
            ans -= n / M[bit];
        else
            ans += n / M[bit];
    }
    cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
