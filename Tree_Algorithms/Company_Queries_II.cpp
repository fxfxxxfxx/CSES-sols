#include <bits/stdc++.h>

using namespace std;

static void solve() {
    static int jump[18][262144]; // 262144 = 2^18
    static int depth[262144];

    int n, q; cin >> n >> q;
    for (int v = 2; v <= n; v++)
        cin >> jump[0][v];
    jump[0][1] = 1;

    for (int k = 1; k < 18; k++)
        for (int i = 0; i <= n; i++)
            jump[k][i] = jump[k-1][jump[k-1][i]];

    depth[1] = 1;
    auto get_depth = [&](int v, auto&& get_depth) -> void {
        int p = jump[0][v];
        if (depth[p] == 0)
            get_depth(p, get_depth);
        depth[v] = depth[p] + 1;
    };
    for (int v = 2; v <= n; v++)
        get_depth(v, get_depth);

    auto dojump = [&](int v, int k) {
        for (int i = 0; i < 18; i++) {
            if (k & 1)
                v = jump[i][v];
            k >>= 1;
        }
        return v;
    };

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        // find min d s.t. diff parent
        int low = 1, high = min(depth[a], depth[b]) + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (dojump(a, depth[a] - mid) != dojump(b, depth[b] - mid))
                high = mid;
            else
                low = mid + 1;
        }
        if (low == depth[a] + 1)
            cout << a << "\n";
        else if (low == depth[b] + 1)
            cout << b << "\n";
        else
            cout << dojump(a, depth[a] - (low - 1)) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
