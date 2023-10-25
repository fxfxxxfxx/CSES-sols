#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> rank, parent;
    UnionFind(int n) {
        rank = vector(n, 0);
        parent = vector(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x] += 1;
    }
};

static void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> E(m);
    for (auto& [c, a, b]: E)
        cin >> a >> b >> c;
    sort(E.begin(), E.end());

    UnionFind uf(n + 1);
    int64_t ans = 0;

    for (auto [c, a, b]: E) {
        if (uf.find(a) == uf.find(b))
            continue;
        ans += c;
        uf.merge(a, b);
    }

    int p = uf.find(1);
    for (int v = 1; v <= n; v++) {
        if (uf.find(v) != p) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
