#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ap(n);
    vector<int> man(m);

    for (int i = 0; i < n; i++)
        cin >> ap[i];
    for (int j = 0; j < m; j++)
        cin >> man[j];

    sort(ap.begin(), ap.end());
    sort(man.begin(), man.end());
    
    int pi = 0, ans = 0;
    for (int pj = 0; pj < m; pj++) {
        while (pi < n && ap[pi] < man[pj] - k) 
            pi += 1;
        if (pi < n && ap[pi] <= man[pj] + k) {
            ans += 1;
            pi += 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
