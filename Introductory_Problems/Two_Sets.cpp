#include <bits/stdc++.h>

using namespace std;

static void print(int n, int st, int st_add) {
    for (int i = st, a = st_add; i <= n; i+=a, a=4-a) {
        cout << i << ((i + a) > n ? "\n": " ");
    }
}

static void solve() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        print(n, 1, 3);
        cout << n / 2 << '\n';
        print(n, 2, 1);
    } else if ((n + 1) % 4 == 0) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        print(n, 3, 1);
        cout << n - n/2 << '\n';
        print(n, 1, 1);
    } else 
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
