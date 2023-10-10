#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int64_t n, k; cin >> n >> k;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    int64_t lsm = 0, rsm = 0;
    int lneed = (k + 1) / 2;
    set<pair<int, int>> L, R;
    for (int i = 0; i < k; i++) {
        R.insert({X[i], i});
        rsm += X[i];
    }
    for (int i = 0; i < lneed; i++) {
        rsm -= R.begin()->first;
        lsm += R.begin()->first;
        L.insert(*R.begin());
        R.erase(R.begin());
    }

    cout << prev(L.end())->first * (lneed - (k - lneed)) - lsm + rsm;
    for (int i = k; i < n; i++) {
        if (X[i] <= prev(L.end())->first) {
            L.insert({X[i], i});
            lsm += X[i];
        } else {
            R.insert({X[i], i});
            rsm += X[i];
        }
        if (L.count({X[i-k], i-k})) {
            L.erase({X[i-k], i-k});
            lsm -= X[i-k];
        } else {
            R.erase({X[i-k], i-k});
            rsm -= X[i-k];
        }
        if (L.size() > lneed) {
            rsm += prev(L.end())->first;
            lsm -= prev(L.end())->first;
            R.insert(*prev(L.end()));
            L.erase(prev(L.end()));
        } else if (L.size() < lneed) {
            lsm += R.begin()->first;
            rsm -= R.begin()->first;
            L.insert(*R.begin());
            R.erase(R.begin());
        }
        cout << " " << prev(L.end())->first * (lneed - (k - lneed)) - lsm + rsm;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
