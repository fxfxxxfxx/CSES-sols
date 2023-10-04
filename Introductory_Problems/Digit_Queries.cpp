#include <bits/stdc++.h>

using namespace std;

static void solveT() {
    int64_t k;
    cin >> k;
    // 9*1, 90*2, 900*3
    int64_t sm = 0, base = 9, start = 1;
    int i = 1;
    for (; i <= 17; i++) {
        if (sm + i * base >= k) break;
        sm += i * base;
        base *= 10;
        start *= 10;
    }
    int64_t res = k - sm;
    // res-th digit of length i
    int64_t q = (res-1) / i, r = (res-1) % i;
    // q-th num, r-th of q-th num
    int64_t num = start + q;
    for (int j = i - 1; j > r; j--)
        num /= 10;
    cout << num % 10 << "\n";
}

static void solve() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
        solveT();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
