#include <bits/stdc++.h>

using namespace std;

void solveT() {
}

static void solve() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i].first;
        cin >> V[i].second;
    }

    vector<int> arg(n);
    iota(arg.begin(), arg.end(), 0);
    sort(arg.begin(), arg.end(), [&](int i, int j) {
        return V[i].first < V[j].first;
    });

    priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> rm;
    queue<int> av;

    vector<int> ans(n);
    for (auto i: arg) {
        auto v = V[i];
        while (!rm.empty() && rm.top().first < v.first) {
            av.push(rm.top().second);
            rm.pop();
        }
        if (av.empty()) {
            ans[i] = rm.size();
        } else {
            ans[i] = av.front();
            av.pop();
        }
        rm.push({v.second, ans[i]});
    }
    int k = av.size() + rm.size();
    cout << k << "\n";
    
    vector<int> out(k);
    iota(out.begin(), out.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(out.begin(), out.end(), g);

    for (int a: ans)
        cout << out[a] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
