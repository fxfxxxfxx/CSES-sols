#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for (int& a: A) cin >> a;

    map<int, pair<int, int>> M;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tar = x - A[i] - A[j];
            if (M.count(tar)) {
                cout << M[tar].first << " " << M[tar].second << " ";
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
        for (int j = 0; j < i; j++)
            M[A[i] + A[j]] = {j + 1, i + 1};
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
