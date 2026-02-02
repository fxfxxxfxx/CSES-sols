#include <bits/stdc++.h>

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

template<int M>
struct Factorial {
    using Mint = mint<M>;

    int N;
    std::vector<Mint> fact, ifact, rev;

    Factorial(int n): N(n + 1), fact(n + 1), ifact(n + 1), rev(n + 1) {
        fact[0] = fact[1] = 1;
        ifact[0] = ifact[1] = 1;
        rev[0] = rev[1] = 1;
        for (int i = 2; i < N; i++) {
            fact[i] = fact[i-1] * i;
            rev[i] = rev[M % i] * (M - M/i);
            ifact[i] = ifact[i-1] * rev[i];
        }
    }

    Mint F(int n) {
        assert(n >= 0);
        return fact[n];
    }

    Mint C(int n, int k) {
        assert(n < N);
        assert(n >= k);
        return fact[n] * ifact[n-k] * ifact[k];
    }

    Mint H(int n, int k) {
        // a_1 + ... + a_n = k
        // a_i >= 0
        return C(n - 1 + k, k);
    }
};


using namespace std;

static void solve() {
    constexpr int M = 1000000007;
    Factorial<M> F(1000001);

    int m; cin >> m;
    if (m & 1) {
        cout << "0\n";
        return;
    }
    string s; cin >> s;
    int n = m / 2, k = s.size();
    int diff = 0;
    for (char c: s) {
        if (c == '(') diff += 1;
        else diff -= 1;
        if (diff < 0) {
            cout << "0\n";
            return;
        }
    }
    n -= (k - diff) / 2;
    n -= diff;
    cout << int(F.C(2*n+diff, n) * (diff+1) / (n+diff+1)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
