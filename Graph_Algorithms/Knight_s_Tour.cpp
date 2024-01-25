#include <bits/stdc++.h>

using namespace std;

constexpr array<pair<int, int>, 128> V = {{
    {5, 4}, {4, 6}, {3, 4}, {1, 5}, {2, 3}, {1, 1}, {3, 2}, {5, 1},
    {7, 2}, {8, 4}, {7, 6}, {8, 8}, {6, 7}, {4, 8}, {2, 7}, {3, 5},
    {1, 6}, {2, 4}, {1, 2}, {3, 1}, {5, 2}, {7, 1}, {8, 3}, {7, 5},
    {8, 7}, {6, 8}, {5, 6}, {6, 4}, {4, 3}, {5, 5}, {6, 3}, {4, 4},
    {6, 5}, {5, 3}, {4, 5}, {3, 3}, {1, 4}, {2, 2}, {4, 1}, {6, 2},
    {8, 1}, {7, 3}, {8, 5}, {7, 7}, {5, 8}, {3, 7}, {1, 8}, {2, 6},
    {3, 8}, {5, 7}, {7, 8}, {8, 6}, {7, 4}, {8, 2}, {6, 1}, {4, 2},
    {2, 1}, {1, 3}, {2, 5}, {1, 7}, {3, 6}, {2, 8}, {4, 7}, {6, 6},
}};

constexpr auto M = [] {
    array<array<int, 9>, 9> ret = {};
    for (int i = 0; i < 64; i++) {
        auto [x, y] = V[i];
        ret[x][y] = i;
    }
    return ret;
}();

static void solve() {
    int x, y; cin >> y >> x;
    int shift = M[x][y];
    for (int x = 1; x <= 8; x++) {
        for (int y = 1; y <= 8; y++) {
            int k = M[x][y] - shift;
            if (k < 0) k += 64;
            cout << k + 1 << " \n"[y == 8];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
