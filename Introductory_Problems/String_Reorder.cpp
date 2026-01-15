#include <bits/stdc++.h>

using namespace std;

static void solve() {
    string s; cin >> s;
    auto n = s.size();

    set<pair<int, char>> I;
    set<pair<char, int>> C;

    int count[128] = {};
    for (const char& c : s)
    count[c] += 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!count[c]) continue;
        I.insert({count[c], c});
        C.insert({c, count[c]});
    }

    string t(n, ' ');
    char c_prev = '\0';
    for (int i = 0; i < n; i++) {
        int remain = n - i;
        int cap = (remain + 1) / 2;
        auto [n_top, c_top] = *prev(I.end());
        auto [c_lex, n_lex] = *C.begin();

        if (n_top > cap) {
            cout << "-1\n";
            return;
        }

        int n_pick = -1;
        char c_pick = '\0';
        if ((remain & 1) && n_top == cap) {
            c_pick = c_top;
            n_pick = n_top;
        } else if (c_lex == c_prev) {
            c_pick = next(C.begin())->first;
            n_pick = next(C.begin())->second;
        } else {
            c_pick = c_lex;
            n_pick = n_lex;
        }
        I.erase({n_pick, c_pick});
        C.erase({c_pick, n_pick});
        if (n_pick > 1) {
            I.insert({n_pick - 1, c_pick});
            C.insert({c_pick, n_pick - 1});
        }
        t[i] = c_pick;
        c_prev = c_pick;
    }
    cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
