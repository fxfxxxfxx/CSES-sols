#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void recursive(int n, int st, int mid, int ed) {
    if (n == 0) return;

    recursive(n - 1, st, ed, mid);
    cout << st << " " << ed << "\n";
    recursive(n - 1, mid, st, ed);
}

static void solve() {
    int n;
    cin >> n;
    
    cout << (1 << n) - 1 << "\n";
    recursive(n, 1, 2, 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
