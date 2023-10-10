#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    set<pair<int,int>> S;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        auto it = S.upper_bound({v, i});
        if (it != S.end())
            S.erase(it);
        S.insert({v, i});
    }
    cout << S.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
