#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, k; cin >> n >> k;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    int64_t low = 0, high = 1e17;
    while (low < high) {
        int64_t mid = (low + high) / 2;
        int64_t cnt = 1, now = 0;
        for (int x: X) {
            if (x > mid) cnt += n;
            if (now + x > mid) {
                cnt += 1;
                now = 0;
            }
            now += x;
        }
        if (cnt > k) low = mid + 1;
        else high = mid;
    }
    cout << low << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
