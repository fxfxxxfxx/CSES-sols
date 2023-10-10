#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    vector<int> V(n+1);
    int i = 0, j = 1, p = 0;
    while (i < n) {
        if (V[j]) {
            j = j % n + 1;
            continue;
        }
        if (p) {
            cout << j << " ";
            i++;
        }
        V[j] = p;
        p ^= 1;
        j = j % n + 1;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
