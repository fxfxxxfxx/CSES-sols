#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; v++) {
        int p; cin >> p;
        adj[p-1].push_back(v);
    }

    vector<int> A(n);
    auto dfs = [&](int v, auto&& dfs) -> int {
        int cnt = 0;
        for (int u: adj[v])
            cnt += dfs(u, dfs);
        A[v] = cnt;
        return cnt + 1;
    };
    dfs(0, dfs);
    for (int a: A)
        cout << a << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
