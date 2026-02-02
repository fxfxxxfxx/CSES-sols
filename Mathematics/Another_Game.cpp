#include <bits/stdc++.h>

using namespace std;

static bool solve() {
    int n; cin >> n;
    vector<int> V(n);
    for (int& v : V) cin >> v;

    for (int v : V)
        if (v & 1)
            return true;
    return false;
}

static void solveT() {
    int t; cin >> t;
    while (t--) cout << (solve() ? "first\n" : "second\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solveT();
    return 0;
}
