#include <bits/stdc++.h>

using namespace std;

static void solveT() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int base = a - (b - a);
    if (base >= 0 && base % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

static void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solveT();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
