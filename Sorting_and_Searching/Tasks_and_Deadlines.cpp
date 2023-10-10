#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<int64_t> V(n);

    int64_t dsm = 0;
    for (int i = 0; i < n; i++) {
        int a, d; cin >> a >> d;
        V[i] = a;
        dsm += d;
    }
    sort(V.begin(), V.end());
    for (int i = 1; i < n; i++)
        V[i] += V[i-1];
    int64_t sm = accumulate(V.begin(), V.end(), int64_t(0));
    cout << dsm - sm << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
