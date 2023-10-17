#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int> V(n);
    for (int& v: V) cin >> v;

    vector<int> S;
    for (int v: V) {
        auto it = lower_bound(S.begin(), S.end(), v);
        if (it == S.end())
            S.push_back(v);
        else
            *it = v;
    }
    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
