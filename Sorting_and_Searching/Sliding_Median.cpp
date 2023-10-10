#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, k; cin >> n >> k;
    vector<int> X(n);
    for (int& x: X) cin >> x;

    int lneed = (k + 1) / 2;
    set<pair<int, int>> L, R;
    for (int i = 0; i < k; i++)
        R.insert({X[i], i});
    for (int i = 0; i < lneed; i++) {
        L.insert(*R.begin());
        R.erase(R.begin());
    }

    cout << prev(L.end())->first;
    for (int i = k; i < n; i++) {
        (X[i] <= prev(L.end())->first ? L : R).insert({X[i], i});
        L.erase({X[i-k], i-k});
        R.erase({X[i-k], i-k});
        if (L.size() > lneed) {
            R.insert(*prev(L.end()));
            L.erase(prev(L.end()));
        } else if (L.size() < lneed) {
            L.insert(*R.begin());
            R.erase(R.begin());
        }
        cout << " " << prev(L.end())->first;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
