#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int x, n;
    cin >> x >> n;

    set<int> P{0, x};
    set<pair<int,int>, greater<pair<int,int>>> L{{x, 0}};

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = P.upper_bound(p);
        int ed = *it;
        it--;
        int st = *it;
        // st, p, ed
        P.insert(p);
        L.erase({ed - st, st});
        L.insert({p - st, st});
        L.insert({ed - p, p});
        cout << L.begin()->first << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
