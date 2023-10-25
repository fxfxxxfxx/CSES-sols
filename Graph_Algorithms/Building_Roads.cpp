#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 1;

static vector<vector<int>> adj;
static int seen[sz];

static void dfs(int vtx) {
    seen[vtx] = 1;
    for (int nxt: adj[vtx]) {
        if (seen[nxt]) continue;
        dfs(nxt);
    }
}

static void solve() {
    int n, m;
    cin >> n >> m;
    adj = decltype(adj)(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    vector<int> vertices;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        ans += 1;
        vertices.push_back(i);
        dfs(i);
    }
    cout << ans - 1 << endl;
    for (int i = 1; i < vertices.size(); i++)
        cout << vertices[i] << " " <<vertices[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
