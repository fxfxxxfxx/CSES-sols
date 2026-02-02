#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m, k; cin >> n >> m >> k;

    constexpr int64_t inf = 2e18;
    vector A(n, vector<int64_t>(n, inf));
    for (int i = 0; i < m; i++) {
        int64_t u, v, c; cin >> u >> v >> c;
        u -= 1; v -= 1;
        A[u][v] = min(A[u][v], c);
    }

    const auto mul = [&](const auto& x, const auto& y) {
        int n = x.size();
        vector z(n, vector<int64_t>(n, inf));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    z[i][j] = min(z[i][j], x[i][k] + y[k][j]);
        return z;
    };

    const auto pow = [&] {
        auto r = A;
        vector res(n, vector<int64_t>(n, inf));
        for (int i = 0; i < n; i++)
            res[i][i] = 0;

        while (k) {
            if (k & 1)
                res = mul(res, r);
            r = mul(r, r);
            k >>= 1;
        }

        return res;
    }();

    auto ans = pow[0][n-1] == inf ? -1 : pow[0][n-1];
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
