#include <bits/stdc++.h>

using namespace std;

static int pow(int a, int b, int m) {
    int64_t ret = 1, mul = a;
    while (b) {
        if (b & 1)
            ret = (ret * mul) % m;
        mul = (mul * mul) % m;
        b >>= 1;
    }
    return ret;
}

static void solve() {
    constexpr int M = 1000000007;
    constexpr int PM = 1000000006;
    constexpr int PPM = 500000002;
    
    int n; cin >> n;
    vector<pair<int, int>> V(n);
    for (auto &[x, k] : V)
        cin >> x >> k;

    int64_t val = 1, sqrt = 1, numExp = 1, valid = 1;
    int64_t num = 1, sum = 1;
    for (auto [x, k] : V) {
        num = num * (k + 1) % M;
        sum = (sum * (pow(x, k+1, M) - 1) % M) * pow(x - 1, M - 2, M) % M;
        val = (val * pow(x, k, M)) % M;
        sqrt = (sqrt * pow(x, k / 2, M)) % M;
        numExp = (numExp * (k + 1)) % PM;
        if (k & 1) valid = 0;
    }
    int64_t prod = -1;
    if (valid) prod = pow(sqrt, numExp, M);
    else prod = pow(val, numExp * pow(2, PPM - 1, PM) % PM, M);
    cout << num << " " << sum << " " << prod << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
