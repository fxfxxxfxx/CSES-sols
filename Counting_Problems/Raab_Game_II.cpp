#include <bits/stdc++.h>

using namespace std;

static constexpr int mod = 1000000007;
static constexpr int N = 5000;
static int D[N+1][N+1];
static int F[N+1];
static int I[N+1];
static int R[N+1];
static auto _ = []{
    D[0][0] = 1;
    for (int n = 2; n <= N; n++) {
        for (int k = 1; k < n; k++) {
            int64_t x = int64_t{k} * D[n-1][k] % mod;
            int64_t y = int64_t{n-k} * D[n-1][k-1] % mod;
            int64_t z = int64_t{n-1} * D[n-2][k-1] % mod;
            D[n][k] = (x + y + z) % mod;
        }
    }

    F[0] = F[1] = 1;
    I[0] = I[1] = 1;
    R[0] = R[1] = 1;
    for (int x = 2; x <= N; x++) {
        F[x] = int64_t{F[x-1]} * x % mod;
        R[x] = int64_t{R[mod % x]} * (mod - mod / x) % mod;
        I[x] = int64_t{I[x-1]} * R[x] % mod;
    }
    return 0;
}();

static int C(int n, int k) {
    return (int64_t{F[n]} * I[k] % mod) * I[n-k] % mod;
}

static int solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int k = n - a - b;
    if (k < 0)
        return 0;
    if (a * b == 0 && a + b > 0)
        return 0;
    return (int64_t{F[n]} * C(n, k) % mod) * D[n-k][a] % mod;
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
