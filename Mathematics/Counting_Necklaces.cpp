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


using namespace std;

static void solve() {
    constexpr int mod = 1000000007;
    int n, m; cin >> n >> m;

    using Mint = mint<mod>;

    // Burnside
    Mint sum = 0;
    for (int i = 0; i < n; i++) {
        // rotate i times
        int g = gcd(i, n);
        sum += Mint{m} ^ g;
    }
    auto ans = sum / n;
    cout << int(ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
