#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n, m;
    cin >> n >> m;

    map<int,int,std::greater<int>> H;
    vector<int> T(m);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        H[p]++;
    } 
    for (int j = 0; j < m; j++)
        cin >> T[j];

    for (int j = 0; j < m; j++) {
        auto it = H.lower_bound(T[j]);
        if (it == H.end())
            cout << "-1\n";
        else {
            cout << it->first << "\n";
            it->second--;
            if (it->second == 0)
                H.erase(it);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
