#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int& a: A) cin >> a;

    map<int, int> M;
    int64_t ans = 0;
    int left = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        M[A[i]] += 1;
        cnt += M[A[i]] == 1;
        while (cnt > k) {
            M[A[left]] -= 1;
            cnt -= M[A[left]] == 0;
            left += 1;
        }
        ans += i - left + 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
