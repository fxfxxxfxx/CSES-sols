#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int median = A[n/2];

    int64_t ans = 0;
    for (int a: A)
        ans += abs(a - median);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
