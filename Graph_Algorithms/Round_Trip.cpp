#include <bits/stdc++.h>

using namespace std;

static const int mxsz = 1e5 + 1;
static vector<int> adj[mxsz];
static int seen[mxsz];
static int vlevel[mxsz];
static int path[mxsz];

[[ noreturn ]] void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

[[ noreturn ]] void printans(int st, int ed) {
    cout << ed - st + 1 << "\n";
    for (int i = st; i < ed; i++) 
        cout << path[i] << " ";
    cout << path[st] << "\n";
    exit(0);
}

static void dfs(int v, int level) {
    if (seen[v]) {
        if (level - vlevel[v] >= 3) 
            printans(vlevel[v], level);
        return;
    }

    seen[v] = 1;
    path[level] = v;
    vlevel[v] = level;

    for (int e: adj[v])
        dfs(e, level + 1);
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
        if(!seen[i]) dfs(i, 0);
    fail();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
