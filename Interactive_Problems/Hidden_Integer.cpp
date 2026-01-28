#include <bits/stdc++.h>

using namespace std;

static void solve() {
    int low = 1, high = 1000000000;
    while (low < high) {
        int mid = low + (high - low) / 2;
        cout << "? " << mid << endl;
        string res; cin >> res;
        bool pred = res[0] == 'N';
        // mid >= x
        if (pred)
            high = mid;
        else
            low = mid + 1;
    }
    cout << "! " << low << endl;
}

int main() {
    solve();
    return 0;
}
