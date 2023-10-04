#include <bits/stdc++.h>

using namespace std;

static char res[8][9];
static int8_t ver[8];
static int8_t dip[16];
static int8_t dim[16];

static int ans = 0;

static void dfs(int level) {
    if (level == 8) {
        ans += 1;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (res[level][i] == '*') continue;
        if (ver[i]) continue;
        if (dip[level + i]) continue;
        if (dim[8 + level - i]) continue;
        ver[i] = dip[level+i] = dim[8 + level - i] = 1;
        dfs(level + 1);
        ver[i] = dip[level+i] = dim[8 + level - i] = 0;
    }
}

static void solve() {
    for (int i = 0; i < 8; i++)
        cin >> res[i];

    dfs(0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
