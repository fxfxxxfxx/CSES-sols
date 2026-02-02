#include <bits/stdc++.h>

using namespace std;

static void solve() {
    static constexpr int lose[] = {0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222};

    int n; cin >> n;
    for (int x : lose) {
        if (n != x)
            continue;
        cout << "second\n";
        return;
    }
    cout << "first\n";
}

static void solveT() {
    int t; cin >> t;
    while (t--) solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solveT();
    return 0;
}
