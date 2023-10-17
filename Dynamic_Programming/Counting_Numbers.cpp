#include <bits/stdc++.h>

using namespace std;

static int64_t count(int64_t bound) {
    if (bound < 0) return 0;
    if (bound == 0) return 1;
    string s = to_string(bound);
    for (char& c: s) c -= '0';

    int same = 1;
    vector<int64_t> dp(10);
    for (int i = 1; i < s[0]; i++)
        dp[i] = 1;
    for (int i = 1; i < int(s.size()); i++) {
        vector<int64_t> curr(10, 1);
        curr[0] = 0;
        int64_t sm = 0;
        for (int j = 0; j < 10; j++)
            sm += dp[j];
        for (int j = 0; j < 10; j++)
            curr[j] += sm - dp[j];
        if (same) {
            for (int j = 0; j < s[i]; j++) {
                if (j == s[i-1]) continue;
                curr[j] += 1;
            }
            if (s[i] == s[i-1]) same = 0;
        }
        dp = curr;
    }
    int64_t ret = 0;
    for (int j = 0; j < 10; j++)
        ret += dp[j];
    return ret + same + 1;
}

static void solve() {
    int64_t a, b; cin >> a >> b;
    cout << count(b) - count(a - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
