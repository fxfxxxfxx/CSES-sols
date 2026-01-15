#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    if ((a + b > n) || ((a * b == 0) && (a + b) > 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> A, B;
    // draw
    int n_draw = n - (a + b);
    for (int i = 0; i < n_draw; i++) {
        A.push_back(n - i);
        B.push_back(n - i);
    }
    // A wins a
    for (int i = 0; i < a; i++) {
        A.push_back(a + b - i);
        B.push_back(a - i);
    }
    // B wins b
    for (int i = 0; i < b; i++) {
        A.push_back(b - i);
        B.push_back(a + b - i);
    }
    for (int a : A)
        cout << a << " ";
    cout << "\n";
    for (int b : B)
        cout << b << " ";
    cout << "\n";
}

static void solveT() {
    int t; cin >> t;
    while (t--) solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solveT();
    return 0;
}
