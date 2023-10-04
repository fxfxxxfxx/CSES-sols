#include <bits/stdc++.h>

using namespace std;

enum class DI {
    D = 0,
    U = 1,
    L = 2,
    R = 3,
    Q = 4,
};

static DI path[49];
static int8_t seen[7][7];

static constexpr int dx[4] = {1, -1, 0, 0};
static constexpr int dy[4] = {0, 0, -1, 1};
static DI mp[128];

static int ans = 0;

static void init() {
    mp['D'] = DI::D;
    mp['U'] = DI::U;
    mp['L'] = DI::L;
    mp['R'] = DI::R;
    mp['?'] = DI::Q;
}

static bool check(int x, int y) {
    if (x < 0 || x > 6) return false;
    if (y < 0 || y > 6) return false;
    if (seen[x][y]) return false;
    return true;
}

static void dfs(int x, int y) {
    static int level = 0;

    if (x == 6 && y == 0) {
        ans += level == 48;
        return;
    }

    if (path[level] != DI::Q) {
        seen[x][y] = 1; level += 1;
        int dir = (int)path[level-1];
        int nx = x + dx[dir], ny = y + dy[dir];
        if (check(nx, ny)) dfs(nx, ny);
        seen[x][y] = 0; level -= 1;
    } else {
        int canbit = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny)) canbit |= 1 << i;
        }
        if (canbit == 0x3 || canbit == 0xC) return;
        seen[x][y] = 1; level += 1;
        for (int i = 0; i < 4; i++) {
            if (!(canbit & (1 << i))) continue;
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx, ny);
        }
        seen[x][y] = 0; level -= 1;
    }
}

static void solve() {
    init();
    char s[49];
    cin >> s;
    for (int i = 0; i < 48; i++)
        path[i] = mp[(int)s[i]];
    dfs(0, 0);
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
