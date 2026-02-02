#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int64_t n; cin >> n;
    vector<int> A(n);
    for (int &a : A) cin >> a;
    vector<int64_t> V(1000001);
    for (int a : A) V[a] += 1;

    vector<int64_t> Q(1000001);
    iota(Q.begin(), Q.end(), 0);
    vector<int64_t> M(1000001);
    for (int p = 2; p <= 1000000; p++) {
        for (int y = p; y <= 1000000; y += p)
            M[p] += V[y];
        if (Q[p] < p) continue;
        for (int64_t y = int64_t{p} * p; y <= 1000000; y += p)
            Q[y] = p;
    }

    int64_t ans = 0;
    for (int a : A) {
        if (a == 1) continue;
        set<int> F;
        while (a > 1) {
            F.insert(Q[a]);
            a /= Q[a];
        }
        vector<int> L(F.begin(), F.end());
        int m = L.size();
        int64_t val = n;
        for (int bit = 1; bit < (1 << m); bit++) {
            int mul = 1, cnt = 0;
            for (int j = 0; j < m; j++)
                if (bit & (1 << j)) {
                    mul *= L[j];
                    cnt += 1;
                }
            if (cnt & 1) val -= M[mul];
            else val += M[mul];
        }
        ans += val;
    }
    ans += V[1] * (n - V[1]);
    ans = ans / 2 + V[1] * (V[1] - 1) / 2;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
