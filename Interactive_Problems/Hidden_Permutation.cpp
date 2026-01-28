#include <bits/stdc++.h>

using namespace std;

static void solve() {
    auto cmp = [](int i, int j) {
        cout << "? " << i << " " << j << endl;
        string res; cin >> res;
        return res[0] == 'Y';
    };

    int n; cin >> n;
    vector<int> I(n);
    iota(I.begin(), I.end(), 1);
    std::stable_sort(I.begin(), I.end(), cmp);

    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        int index = I[i-1];
        ans[index-1] = i;
    }
    cout << "!";
    for (int a : ans)
        cout << " " << a;
    cout << endl;
}

int main() {
    solve();
    return 0;
}
