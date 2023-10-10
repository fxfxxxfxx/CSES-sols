#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for (int& a: A) cin >> a;

    int64_t sm = 0, st = 0, cnt = 0;
    for (int ed = 0; ed < n; ed++) {
        sm += A[ed];
        while (sm > x) {
            sm -= A[st];
            st += 1;
        }
        if (sm == x) cnt += 1;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
