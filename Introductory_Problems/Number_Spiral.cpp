#include <bits/stdc++.h>
#include <cstdarg>

using namespace std;

static void solveT() {
    int y, x;
    cin >> y >> x;

    uint64_t lay = max(y, x);
    uint64_t base = (lay - 1) * (lay - 1);
    if (!(lay & 1))
        swap(x, y);
    // horizon
    if (y == lay) {
        cout << base + x;
    } else {
        cout << base + lay + (lay - y);
    }
    cout << '\n';
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
