#include <bits/stdc++.h>

using namespace std;

static int8_t room[1000][1000];

static int n, m;
void dfs(int x, int y) {
    if (x < 0 || x > n - 1) return;
    if (y < 0 || y > m - 1) return;
    if (room[x][y] == '#') return;

    room[x][y] = '#';
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

static void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (room[i][j] == '.') {
                dfs(i, j);
                ans += 1;
            }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
