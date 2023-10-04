#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

int n;
vector<string> ans;
vector<char> cnt(128);

void dfs(string& s, int layer) {
    if (layer == n) {
        ans.push_back(s);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (!cnt[c]) continue;
        s[layer] = c;
        cnt[c]--;
        dfs(s, layer + 1);
        cnt[c]++;
    }
}

static void solve() {
    string s;
    cin >> s;

    n = s.length();

    for (char c: s) cnt[c]++;
    dfs(s, 0);

    cout << ans.size() << "\n";
    for (string t: ans)
        cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
