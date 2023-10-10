#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> et;
    vector<pair<int,int>> st(n);

    for (int i = 0; i < n; i++) {
        cin >> st[i].first >> st[i].second;
    }
    sort(st.begin(), st.end());
    
    int ans = 0;
    for (auto &s : st) {
        while (!et.empty() && et.top() < s.first) 
            et.pop();
        et.push(s.second);
        ans = max(ans, (int)et.size());
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
