#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> T(n);
    for (int& t: T) cin >> t;
    sort(T.begin(), T.end());
    int64_t sm = accumulate(T.begin(), T.end(), int64_t(0));
    if (T.back() * 2 > sm)
        cout << T.back() * 2 << endl;
    else
        cout << sm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
