#include <bits/stdc++.h>

using namespace std;


struct bitset128 {
    uint64_t data[2];
    constexpr bitset128() {
        data[0] = data[1] = ~(0ULL);
    }
    constexpr bitset128(uint64_t a, uint64_t b) {
        data[0] = a;
        data[1] = b;
    }
    constexpr void reset(int i) {
        if (i < 64) data[0] &= ~(1ULL << (63 - i));
        else data[1] &= ~(1ULL << (127 - i));
    }
    constexpr int find_first() {
        if (data[0]) {
            return __builtin_clzll(data[0]);
        } else if (data[1]) {
            return 64 + __builtin_clzll(data[1]);
        } else
            return 128;
    }
    constexpr bitset128 operator&(const bitset128& other) {
        return bitset128{data[0] & other.data[0], data[1] & other.data[1]};
    }
};

static constexpr auto ans = []{
    using T = bitset128;
    array<array<int16_t, 101>, 101> ret = {};
    array<T, 101> R = {};
    array<T, 101> C = {};

    for (int r = 0; r <= 100; r++) {
        for (int c = 0; c <= 100; c++) {
            T res = R[r] & C[c];
            int toput = res.find_first();
            R[r].reset(toput);
            C[c].reset(toput);
            ret[r][c] = toput;
        }
    }
    return ret;
}();

static void solve() {
    int n; cin >> n;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << ans[r][c] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
