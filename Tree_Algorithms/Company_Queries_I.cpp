#include <bits/stdc++.h>

using namespace std;

static void solve() {
    static int jump[18][262144]; // 262144 = 2^18

    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; i++)
        cin >> jump[0][i];
    jump[0][0] = jump[0][1] = 0;

    for (int k = 1; k < 18; k++)
        for (int i = 0; i <= n; i++)
            jump[k][i] = jump[k-1][jump[k-1][i]];

    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        for (int i = 0; i < 18; i++) {
            if (k & 1)
                x = jump[i][x];
            k >>= 1;
        }
        int res = x == 0 ? -1 : x;
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
