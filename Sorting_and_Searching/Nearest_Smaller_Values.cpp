#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;

    stack<pair<int, int>> S;
    S.emplace(0, 0);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (S.top().first >= x)
            S.pop();
        cout << S.top().second << " ";
        S.emplace(x, i);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
