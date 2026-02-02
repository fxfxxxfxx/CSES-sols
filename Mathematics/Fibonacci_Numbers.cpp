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


class T {
    using Mint = mint<1000000007>;
public:
    Mint _00, _01, _10, _11;
    T() {}
    T(Mint a, Mint b, Mint c, Mint d) : _00(a), _01(b), _10(c), _11(d) {}
    T(const T& o) : _00(o._00), _01(o._01), _10(o._10), _11(o._11) {}
    T& operator *=(T o) {
        return *this = {
            _00 * o._00 + _01 * o._10,
            _00 * o._10 + _01 * o._11,
            _10 * o._00 + _11 * o._10,
            _10 * o._10 + _11 * o._11
        };
    }
    T& operator ^=(int64_t x) {
        T res{1, 0, 0, 1}, mul{*this};
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
    auto r = T{0, 1, 1, 1} ^ n;
    cout << int(r._01) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
