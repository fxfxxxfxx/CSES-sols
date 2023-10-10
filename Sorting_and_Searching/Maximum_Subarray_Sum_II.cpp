#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    vector<int64_t> V{0};
    for (int x: X) V.push_back(V.back() + x);
    set<pair<int64_t, int>> S;

    int64_t ans = -1e16;
    for (int i = 0; i <= n; i++) {
        // i - a     --> valid
        // i - b - 1 --> invalid
        if (i - b - 1 >= 0)
            S.erase({V[i - b - 1], i - b - 1});
        if (i - a >= 0)
            S.insert({V[i - a], i - a});
        if (!S.empty())
            ans = max(ans, V[i] - S.begin()->first);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
