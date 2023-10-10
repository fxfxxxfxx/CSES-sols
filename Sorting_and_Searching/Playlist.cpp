#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static int readInt() {
    int p;
    cin >> p;
    return p;
}

static void solve() {
    int n = readInt();
    map<int, int> M;

    int pos = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = readInt();
        pos = max(pos, M[k]);
        ans = max(ans, i - pos);
        M[k] = i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
