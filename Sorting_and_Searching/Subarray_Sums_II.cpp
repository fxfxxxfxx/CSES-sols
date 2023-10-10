#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for (int& a: A) cin >> a;

    map<int64_t, int> M;
    M[0] = 1;
    int64_t sm = 0, ans = 0;
    for (int a: A) {
        sm += a;
        ans += M[sm - x];
        M[sm] += 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
