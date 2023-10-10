#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];

    sort(V.begin(), V.end());

    int64_t sf = 0;
    for (int v: V) {
        if (sf + 1 < v) {
            cout << sf + 1 << "\n";
            return;
        }
        sf = v + sf;
    }
    cout << sf + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
