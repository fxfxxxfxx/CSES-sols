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
    explicit operator int() { return x; }
};


struct T {
    using Mint = mint<1000000007>;
    using Matrix = array<array<Mint, 6>, 6>;
    static inline const Matrix unit = [] {
        Matrix r{};
        for (int i = 0; i < 6; i++)
            r[i][i] = 1;
        return r;
    }();

    Matrix A;

    T() {}
    T(const T& o) : A(o.A) {}
    T(const Matrix& mt) : A(mt) {}
    T& operator *=(const T& o) {
        T res{};
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    res.A[i][j] += A[i][k] * o.A[k][j];
        return *this = res;
    }

    T& operator ^=(int64_t x) {
        T res{unit}, mul{*this};
        while (x) {
            if (x & 1)
                res *= mul;
            mul *= mul;
            x >>= 1;
        }
        return *this = res;
    }
    friend T operator *(const T x, const T y) { return T(x) *= y; }
    friend T operator ^(const T x, const int64_t y) { return T(x) ^= y; }
};

static void solve() {
    int64_t n; cin >> n;
    const T trans = T::Matrix{{
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    }};
    auto r = trans ^ n;
    cout << int(r.A[5][5]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
