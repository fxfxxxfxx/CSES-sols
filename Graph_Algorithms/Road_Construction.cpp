#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    int n_comp;
    vector<int> rank, parent, sz;
    UnionFind(int n) : n_comp(n) {
        rank = vector(n, 0);
        parent = vector(n, 0);
        sz = vector(n, 1);
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
        n_comp -= 1;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        if (rank[x] == rank[y])
            rank[x] += 1;
    }
};

static void solve() {
    int n, m; cin >> n >> m;

    int mx = 1;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a--; b--;

        a = uf.find(a);
        b = uf.find(b);
        uf.merge(a, b);
        mx = max({mx, uf.sz[a], uf.sz[b]});
        cout << uf.n_comp << " " << mx << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
