#include <bits/stdc++.h>

using namespace std;
using T = array<int, 3>; // x, y, isM

static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

static int n, m;
static char maze[1000][1001];
static char bt[1000][1001];
static queue<T> Q;
static int sx, sy;

[[ noreturn ]] void out(int x, int y, int d) {
    cout << "YES\n";
    cout << d << "\n";
    string s(d, ' ');
    for (int i = d - 1; i >= 0; i--) {
        int j = bt[x][y];
        x += dx[j ^ 1], y += dy[j ^ 1];
        s[i] = "DURL"[j];
    }
    cout << s << "\n";
    exit(0);
}

static bool valid(int x, int y) {
    if (x < 0 || x > n - 1) return false;
    if (y < 0 || y > m - 1) return false;
    if (maze[x][y] == '#') return false;
    return true;
}

static void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'M') {
                Q.push({i, j, 1});
                maze[i][j] = '#';
            } else if (maze[i][j] == 'A') {
                sx = i, sy = j;
                maze[i][j] = '#';
            }
        }
    }
    Q.push({sx, sy, 0});
    for (int dis = 0; !Q.empty(); dis++) {
        int sz = Q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y, isM] = Q.front();
            Q.pop();
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                if (isM == 0) out(x, y, dis);
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!valid(nx, ny)) continue;
                maze[nx][ny] = '#';
                if (isM == 0)
                    bt[nx][ny] = i;
                Q.push({nx, ny, isM});
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
