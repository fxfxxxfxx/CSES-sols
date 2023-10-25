#include <bits/stdc++.h>

using namespace std;

static const int mxsz = 1e5 + 1;

static int8_t team[mxsz];
static vector<int> adj[mxsz];

[[ noreturn ]] void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

static void dfs(int v, int t) {
    if (team[v] != 0) {
        if (team[v] != t) fail();
        return;
    }
    team[v] = t;
    for (int e: adj[v])
        dfs(e, 3 - t);
}

static void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!team[i]) dfs(i, 1);

    for (int i = 1; i <= n; i++)
        cout << (int)team[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
