#include <bits/stdc++.h>

using namespace std;

static void solve() {
    constexpr int mod = 1e9 + 7;
    int n; cin >> n;
    vector<string> S(n);
    for (auto& s: S) cin >> s;

    vector<vector<int>> M(n, vector<int>(n));
    M[0][0] = S[0][0] == '.';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (S[i][j] == '*') continue;
            if (i >= 1) M[i][j] = (M[i][j] + M[i-1][j]) % mod;
            if (j >= 1) M[i][j] = (M[i][j] + M[i][j-1]) % mod;
        }
    cout << M[n-1][n-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
