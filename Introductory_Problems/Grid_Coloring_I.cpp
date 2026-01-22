#include <bits/stdc++.h>

using namespace std;

static char board[512][512];

static void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A' || board[i][j] == 'B') {
                board[i][j] = 'C' + ((i + j) & 1);
            } else {
                board[i][j] = 'A' + ((i + j) & 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << board[i] << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
