#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    int64_t sm = 0;
    vector<int> objs;
    for (int i = 0; i < n; i++) {
        int o;
        cin >> o;
        objs.push_back(o);
        sm += o;
    }

    sort(objs.begin(), objs.end());

    int64_t mn = 2 * sm;
    for (int i = 0; i < (1 << n); i++) {
        int64_t cand = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                cand += objs[j];
            int64_t res = abs(sm - 2 * cand);
            if (res < mn) {
                mn = res;
            }
        }
    }
    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
