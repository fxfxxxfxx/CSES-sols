#include <bits/stdc++.h>

using namespace std;

template <typename Monoid>
struct SegTree {
private:
    using T = typename Monoid::value_type;
    size_t n;
    std::vector<T> V;

    void _set(int i, T v, int vl, int vr, int pos) {
        if (vl + 1 == vr) { V[pos] = v; return; }
        int mid = vl + (vr - vl) / 2;
        if (i < mid) _set(i, v, vl, mid, pos * 2);
        else _set(i, v, mid, vr, pos * 2 + 1);
        V[pos] = Monoid::op(V[pos * 2], V[pos * 2 + 1]);
    }
    T _query(int ql, int qr, int vl, int vr, int pos) {
        if (vr <= ql || qr <= vl) return Monoid::unit;
        if (ql <= vl && vr <= qr) return V[pos];
        int mid = vl + (vr - vl) / 2;
        T left = _query(ql, qr, vl, mid, pos * 2);
        T right = _query(ql, qr, mid, vr, pos * 2 + 1);
        return Monoid::op(left, right);
    }
    void _build(const std::vector<T>& data, int vl, int vr, int pos) {
        if (vl + 1 == vr) { V[pos] = data[vl]; return; }
        int mid = vl + (vr - vl) / 2;
        _build(data, vl, mid, pos * 2);
        _build(data, mid, vr, pos * 2 + 1);
        V[pos] = Monoid::op(V[pos * 2], V[pos * 2 + 1]);
    }
public:
    SegTree(int n): n(n) { V = std::vector<T>(n << 2, Monoid::unit); }
    SegTree(const std::vector<T>& data): n(data.size()) {
        V = std::vector<T>(n << 2, Monoid::unit);
        _build(data, 0, n, 1);
    }
    void set(int i, T v) { _set(i, v, 0, n, 1); }
    T query(int ql, int qr) { return _query(ql, qr, 0, n, 1); }
};


struct T {
    using value_type = int;
    inline static int unit = 0;
    static int op(int a, int b) { return a + b; }
};

static void solve() {
    int n; cin >> n;
    vector<int> S;

    vector<array<int, 3>> V(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y, idx] = V[i];
        cin >> x >> y;
        S.push_back(x);
        S.push_back(y);
        idx = i;
    }
    sort(S.begin(), S.end());
    map<int, int> M;
    for (int i = 0; i < 2 * n; i++)
        M[S[i]] = i;

    for (auto& [x, y, _]: V)
        x = M[x], y = M[y];

    sort(V.begin(), V.end(), [](const auto &x, const auto &y) {
        return x[1] == y[1] ? x[0] > y[0] : x[1] < y[1];
    });

    int cnt = 2 * n;
    {
        SegTree<T> st(cnt);
        vector<int> ans(n);
        vector<int> C(cnt);
        for (auto [x, _, idx]: V) {
            ans[idx] = st.query(x, cnt);
            C[x] += 1;
            st.set(x, C[x]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    reverse(V.begin(), V.end());
    {
        SegTree<T> st(cnt);
        vector<int> ans(n);
        vector<int> C(cnt);
        for (auto [x, _, idx]: V) {
            ans[idx] = st.query(0, x + 1);
            C[x] += 1;
            st.set(x, C[x]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
