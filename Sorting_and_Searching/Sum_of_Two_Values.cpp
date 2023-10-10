#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n, x;
    cin >> n >> x;

    map<int,int> M;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int needed = x - p;
        if (M.count(needed)) {
            cout << M[needed] << " " << i + 1 << "\n";
            return;
        }
        M[p] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
