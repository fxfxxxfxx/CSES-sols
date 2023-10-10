#include <bits/stdc++.h>

using namespace std;

template <typename I, typename Predicate>
requires std::is_integral_v<I> && predicate<Predicate, I>
constexpr I bsearch(I low, I high, Predicate pred) {
    while (low < high) {
        const I mid = low + (high - low) / 2;
        if (pred(mid)) high = mid;
        else low = mid + 1;
    }
    return low;
};

static void solve() {
    int n, t; cin >> n >> t;
    vector<int> K(n);
    for (int& k: K) cin >> k;
    int64_t ans = bsearch<int64_t>(1, 1e18, [&](int64_t v) {
        int64_t cnt = 0;
        for (int k: K) {
            cnt += v / k;
            if (cnt >= t) return true;
        }
        return false;
    });
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
