#include <bits/stdc++.h>

using namespace std;

template<int M>
struct mint {
private:
    int pow(int a, int b) {
        int64_t res = 1, mul = a;
        while (b) {
            if (b & 1) res = (res * mul) % M;
            mul = (mul * mul) % M;
            b >>= 1;
        }
        return res;
    }
public:
    int x;
    mint() : x(0) {}
    mint(int x) : x(x) {}
    mint& operator +=(mint o) {
        x = (x + o.x) % M;
        x = (x + M) % M;
        return *this;
    }
    mint& operator -=(mint o) {
        x = (x - o.x) % M;
        x = (x + M) % M;
        return *this;
    }
    mint& operator *=(mint o) {
        x = int64_t(x) * o.x % M;
        x = (x + M) % M;
        return *this;
    }
    mint& operator ^=(mint o) {
        x = pow(x, o.x);
        x = (x + M) % M;
        return *this;
    }
    mint& operator /=(mint o) {
        int rev_y = pow(o.x, M - 2);
        x = int64_t(x) * rev_y % M;
        x = (x + M) % M;
        return *this;
    }

    friend mint operator +(const mint x, const mint y) { return mint(x) += y; }
    friend mint operator -(const mint x, const mint y) { return mint(x) -= y; }
    friend mint operator *(const mint x, const mint y) { return mint(x) *= y; }
    friend mint operator /(const mint x, const mint y) { return mint(x) /= y; }
    friend mint operator ^(const mint x, const mint y) { return mint(x) ^= y; }
    friend bool operator <(const mint x, const mint y) { return x.x < y.x; }
    friend bool operator <=(const mint x, const mint y) { return x.x <= y.x; }
    friend bool operator >(const mint x, const mint y) { return x.x > y.x; }
    friend bool operator >=(const mint x, const mint y) { return x.x >= y.x; }
    friend bool operator ==(const mint x, const mint y) { return x.x == y.x; }
    friend bool operator !=(const mint x, const mint y) { return x.x != y.x; }
    explicit operator int() const { return x; }
};

static void solve() {
    using Mint = mint<1000000007>;
    int n, m, k; cin >> n >> m >> k;

    using Matrix = vector<vector<Mint>>;

    // A[i][j] = 1   <==>   (j,i) \in E
    Matrix A(n, vector<Mint>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u -= 1; v -= 1;
        A[v][u] += 1;
    }

    const auto mul = [](const Matrix& x, const Matrix& y) {
        int n = x.size();
        Matrix z(n, vector<Mint>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    z[i][j] += x[i][k] * y[k][j];
        return z;
    };

    const auto pow = [&] {
        auto r = A;
        vector res(n, vector<Mint>(n));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (k) {
            if (k & 1)
                res = mul(res, r);
            r = mul(r, r);
            k >>= 1;
        }

        return res;
    }();

    auto ans = int(pow[n-1][0]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
