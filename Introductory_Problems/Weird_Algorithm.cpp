#include <bits/stdc++.h>

using namespace std;

static void solve() {
    uint64_t n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        n = (n & 1) ? (n * 3 + 1) : (n >> 1);
    }
    cout << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
