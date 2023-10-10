#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> V(n);
    for (auto& [a, b]: V)
        cin >> a >> b;
    sort(V.begin(), V.end(), [](const auto& x, const auto& y){
        return x.second == y.second ? x.first < y.first : x.second < y.second;
    });

    int ans = 0;
    set<pair<int,int>> S;
    for (int i = 0; i < k; i++)
        S.insert({0, i});
    for (auto [a, b]: V) {
        auto it = S.upper_bound({a, k});
        if (it == S.begin()) continue;
        ans += 1;
        auto [ed, i] = *prev(it);
        S.erase(prev(it));
        S.insert({b, i});
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
