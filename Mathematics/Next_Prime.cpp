#include <bits/stdc++.h>

using namespace std;

static int64_t solve() {
    auto mul = [](uint64_t a, uint64_t b, uint64_t mod) {
        uint64_t res = 0;
        a %= mod;
        while (b) {
            if (b & 1)
                res = (mod - res > a) ? res + a : res + a - mod;
            a = (mod - a > a) ? a + a : a + a - mod;
            b >>= 1;
        }
        return res;
    };

    auto pow = [&](uint64_t a, uint64_t b, uint64_t mod) {
        uint64_t res = 1;
        a %= mod;
        while (b) {
            if (b & 1)
                res = mul(res, a, mod);
            a = mul(a, a, mod);
            b >>= 1;
        }
        return res;
    };

    auto miller_rabin = [&](uint64_t x, uint64_t base) {
        if (base % x == 0) return true;
        uint64_t d = x - 1, s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s += 1;
        }

        uint64_t z = pow(base, d, x);
        if (z == 1 || z == (x - 1)) return true;

        for (int r = 1; r < s; r++) {
            z = mul(z, z, x);
            if (z == x - 1) return true;
        }
        return false;
    };

    auto is_prime = [&](uint64_t x) {
        // 2, 13, 23, 1662803 can decide n <= 1,122,004,669,633
        constexpr uint64_t bases[4] = {2, 13, 23, 1662803};

        if (x < 2) return false;
        for (uint64_t base : bases) {
            if (x == base) return true;
            if (!miller_rabin(x, base)) return false;
        }
        return true;
    };

    uint64_t n; cin >> n;
    if (n == 1) return 2;

    // https://en.wikipedia.org/wiki/Prime_gap
    // max gap <= 10^12 is 540
    for (uint64_t p = (n+1) | 1; p <= n + 540; p += 2)
        if (is_prime(p)) return p;
    __builtin_unreachable();
}

static void solveT() {
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solveT();
    return 0;
}
