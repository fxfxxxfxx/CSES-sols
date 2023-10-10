#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    vector<int> idx(n+1);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        idx[p] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n-1; i++) {
        ans += idx[i+1] < idx[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
