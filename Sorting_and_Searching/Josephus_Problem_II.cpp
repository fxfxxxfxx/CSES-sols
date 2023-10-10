#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename Key>
using ordered_set = tree<
    Key,
    null_type,
    less<Key>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


static void solve() {
    int n, k; cin >> n >> k;
    ordered_set<int> S;
    for (int i = 0; i < n; i++)
        S.insert(i);

    int target = 0;
    while (!S.empty()) {
        target = (target + k) % S.size();
        auto it = S.find_by_order(target);
        cout << *it + 1 << " ";
        S.erase(it);
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
