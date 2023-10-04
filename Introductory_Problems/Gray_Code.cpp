#include <bits/stdc++.h>

using namespace std;

template <int N>
void run() {
    bitset<N> b(0);
    for (uint32_t i = 0; i < (1 << N); i++) {
        bitset<N> fp(i ^ (i & (i-1)));
        b ^= fp;
        cout << b.to_string() << "\n";
    }
}

static void solve() {
    int n;
    cin >> n;
    switch (n) {
        case 1: run<1>(); break;
        case 2: run<2>(); break;
        case 3: run<3>(); break;
        case 4: run<4>(); break;
        case 5: run<5>(); break;
        case 6: run<6>(); break;
        case 7: run<7>(); break;
        case 8: run<8>(); break;
        case 9: run<9>(); break;
        case 10: run<10>(); break;
        case 11: run<11>(); break;
        case 12: run<12>(); break;
        case 13: run<13>(); break;
        case 14: run<14>(); break;
        case 15: run<15>(); break;
        case 16: run<16>(); break;
        default: return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
