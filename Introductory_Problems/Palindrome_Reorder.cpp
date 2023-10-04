#include <bits/stdc++.h>

using namespace std;

void solveT() {}

static void solve() {
    string s;
    cin >> s;
    
    int cnt[128] = {};
    for (char c: s)
        cnt[(int)c] += 1;

    string ans;

    int odd = -1;
    for (int i = 0; i < 128; i++) {
        if (cnt[i] & 1) {
            if (odd == -1) odd = i;
            else {
                cout << "NO SOLUTION\n";
                return;
            }
        }
        for (int j = 0; j < cnt[i]/2; j++)
            ans.push_back(i);
    }
    if (odd != -1)
        ans.push_back(odd);
    for (int i = 127; i >= 0; i--) {
        for (int j = 0; j < cnt[i]/2; j++)
            ans.push_back(i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
