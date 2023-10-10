#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int& a: A) cin >> a;
    map<int, int> M;
    M[0] = 1;
    int64_t sm = 0, ans = 0;
    for (int a: A) {
        sm = (sm + a) % n;
        sm = (sm + n) % n;
        ans += M[sm];
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
