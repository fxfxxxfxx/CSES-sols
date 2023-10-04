#include <bits/stdc++.h>
#include <cstdarg>

using namespace std;

static void solve() {
    int n;
    cin >> n;
    switch (n) {
    case 1: 
        cout << "1\n";
    case 2:
    case 3:
        cout << "NO SOLUTION\n";
    case 4:
        cout << "3 1 4 2\n";
    default:
        for (int i = 1; i <= n; i+=2)
            cout << i << ' ';
        for (int i = 2; i <= n; i+=2)
            cout << i << ((i + 2 <= n) ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
