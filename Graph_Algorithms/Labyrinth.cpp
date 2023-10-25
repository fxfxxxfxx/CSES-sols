#include <bits/stdc++.h>

using namespace std;

using Pos = pair<int,int>;
static int room[1000][1000];
static Pos A, B;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dname[] = {'U', 'D', 'L', 'R'}; // inverted

const int SPACE = -1;
const int WALL = -2;

static int n, m;

static bool inbound(int x, int y) {
    if (x < 0 || x > n - 1) return false;
    if (y < 0 || y > m - 1) return false;
    return true;
}

static bool check(int x, int y) {
    if (!inbound(x, y)) return false;
    if (room[x][y] != SPACE) return false;
    return true;
}

[[ noreturn ]] void answer() {
    int ans = room[B.first][B.second];

    cout << "YES\n" << ans << endl;

    char *path = new char[ans + 1]();

    auto [x, y] = B;
    for (int i = ans - 1; i >= 0; i--) {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!inbound(nx, ny)) continue;
            if (room[nx][ny] != i) continue;
            path[i] = dname[d];
            x = nx, y = ny;
            break;
        }
    }
    cout << path << endl;

    exit(0);
}

static void bfs() {
    queue<Pos> Q;
    Q.push(A);

    room[A.first][A.second] = 0;
    for (int i = 0; !Q.empty(); i++) {
        int sz = Q.size();
        for (int j = 0; j < sz; j++) {
            auto [x, y] = Q.front();
            Q.pop();

            if (B == Pos{x, y}) answer();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (!check(nx, ny)) continue;
                Q.push({nx, ny});
                room[nx][ny] = i + 1;
            }
        }
    }
}

static void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            room[i][j] = ch == '#' ? WALL : SPACE;
            if (ch == 'A') 
                A = {i, j};
            if (ch == 'B') 
                B = {i, j};
        }
    bfs();
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
