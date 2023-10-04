#include <bits/stdc++.h>

using namespace std;

static int get_xsum(int n) {
    const int ret[4] = {
        n, 1, n + 1, 0
    };
    return ret[n % 4];
}

static void solve() {
    int n;
    cin >> n;
    
    int xsum = get_xsum(n);
    for (int i = 1; i < n; i++) {
        int m;
        cin >> m;
        xsum ^= m;
    }

    cout << xsum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
