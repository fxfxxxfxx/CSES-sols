#include <bits/stdc++.h>

using namespace std;

static const int mxsz = 1e5 + 1;

static vector<int> adj[mxsz];
static int dis[mxsz];

[[ noreturn ]] void printans(int n) {
    vector<int> ans(dis[n] - 1);

    cout << dis[n] << "\n";
    for (int d = dis[n], v = n; v != 1; d--) {
        for (int e: adj[v]) {
            if (dis[e] != d - 1) 
                continue;
            v = e;
            break;
        }
        ans[d-2] = v;
    }
    for (int v: ans)
        cout << v << " ";
    cout << n << "\n";
    exit(0);
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

    queue<int> Q;
    Q.push(1);
    dis[1] = 1;

    for (int ans = 1; !Q.empty(); ans++) {
        int sz = Q.size();
        for (int i = 0; i < sz; i++) {
            int front = Q.front();
            Q.pop();
            
            if (front == n) {
                printans(n);
            }

            for (int e: adj[front]) {
                if (dis[e]) continue;
                Q.push(e);
                dis[e] = ans + 1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
