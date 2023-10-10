#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

int readInt() {
    int x = 0;
    char c = getchar();
    while (c == '\n' || c == ' ') c = getchar();
    while ('0' <= c && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

static void solve() {
    int n = readInt();
    set<int> S;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m = readInt();
        if (S.find(m) != S.end()) continue;
        S.insert(m);
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
