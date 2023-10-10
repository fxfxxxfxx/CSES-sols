#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> W;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        W.push_back(m);
    }

    sort(W.begin(), W.end());

    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (W[r] + W[l] <= x) {
            l++;
        }
        r--;
        ans++;
    }
    if (l == r) ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
