#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    set<pair<int,int>> M;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        M.insert({b, a});
    }

    int lastEnd = -1;
    int ans = 0;
    for (pair<int,int> p : M) {
        // (end, start)
        if (p.second < lastEnd)
            continue;
        ans++;
        lastEnd = p.first;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
