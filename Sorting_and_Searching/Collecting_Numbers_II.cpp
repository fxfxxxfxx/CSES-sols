#include <bits/stdc++.h>

using namespace std;

static int change(vector<int>& idx, int i, int val, int n) {
    int diff = 0;

    if (i > 1) {
        diff -= (idx[i] < idx[i-1]);
        diff += (val < idx[i-1]);
    }
    if (i < n) {
        diff -= (idx[i+1] < idx[i]);
        diff += (idx[i+1] < val);
    }

    idx[i] = val;

    return diff;
}

static void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> idx(n+1), org(n+1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        org[i] = p;
        idx[p] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n-1; i++)
        ans += idx[i+1] < idx[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int va = org[a], vb = org[b];
        swap(org[a], org[b]);
        ans += change(idx, va, b, n);
        ans += change(idx, vb, a, n);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
