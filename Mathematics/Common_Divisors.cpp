#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int N = 1000000;
    static int8_t V[N + 1];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        V[x] += 1;
    }

    for (int v = N; v > 0; v--) {
        int cnt = 0;
        for (int u = v; u <= N; u += v)
            cnt += V[u];
        if (cnt >= 2) {
            cout << v << "\n";
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
