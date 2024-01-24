#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int K = 1000000007;
    int n, m; cin >> n >> m;

    int oadj[20][20] = {};
    int iadj[20][20] = {};

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a -= 1; b -= 1;
        oadj[a][b] += 1;
        iadj[b][a] += 1;
    }

    static int odp[20][1<<20] = {};
    static int idp[20][1<<20] = {};

    odp[0][1] = 1;
    idp[n-1][1<<(n-1)] = 1;

    static vector<int> iM[21][20];
    static vector<int> oM[21][20];

    for (int bit = 0; bit < (1<<n); bit++) {
        int cnt = bitset<20>(bit).count();
        if (bit & 1) {
            for (int i = 0; i < 20; i++)
                if (bit & (1 << i)) oM[cnt][i].push_back(bit);
        }
        if (bit & (1 << (n-1))) {
            for (int i = 0; i < 20; i++)
                if (bit & (1 << i)) iM[cnt][i].push_back(bit);
        }
    }

    auto span = [](auto &E, auto &arr, auto &adj) {
        for (int v = 0; v < 20; v++) {
            for (int bit : E[v]) {
                for (int u = 0; u < 20; u++) {
                    if (bit & (1 << u)) continue;
                    int nbit = bit | (1 << u);
                    arr[u][nbit] = (arr[u][nbit] + (int64_t(arr[v][bit]) * adj[v][u] % K)) % K;
                }
            }
        }
    };

    int left = n / 2, right = n - left;
    for (int i = 1; i < left; i++)
        span(oM[i], odp, oadj);
    for (int i = 1; i < right; i++)
        span(iM[i], idp, iadj);

    int64_t ans = 0;
    for (int v = 0; v < n; v++) {
        for (int bit : oM[left][v]) {
            int com = bit ^ ((1<<n) - 1);
            for (int u = 0; u < n; u++) {
                int64_t mul = int64_t(odp[v][bit]) * idp[u][com] % K;
                ans = (ans + mul * oadj[v][u]) % K;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
