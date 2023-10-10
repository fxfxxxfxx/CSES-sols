#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        int tar = x - A[i].first;
        int st = i + 1, ed = n - 1;
        while (st < ed) {
            if (A[st].first + A[ed].first > tar)
                ed -= 1;
            else if (A[st].first + A[ed].first < tar)
                st += 1;
            else {
                cout << A[i].second << " " << A[st].second << " " << A[ed].second << "\n";
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
