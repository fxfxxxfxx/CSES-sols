#include <bits/stdc++.h>

using namespace std;

static int answer[1024][1024];
static auto _ = []{
    memset(answer, 0xff, sizeof(int) * 1024 * 1024);
    return 0;
}();

static void solve() {
    static constexpr int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    static constexpr int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    int n; cin >> n;
    queue<pair<int,int>> Q;
    answer[0][0] = 0;
    Q.push({0, 0});
    for (int r = 1; !Q.empty(); r++) {
        int sz = Q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = Q.front(); Q.pop();
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (answer[nx][ny] != -1)
                    continue;
                answer[nx][ny] = r;
                Q.push({nx, ny});
            }
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            cout << answer[x][y] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
