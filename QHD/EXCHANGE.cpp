#include <bits/stdc++.h>
#define NAME "EXCHANGE"
#define lim 10000001
#define MOD 1000000007
using namespace std;
int T, N, C[lim];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    C[0] = 1;
    for(int b = 1; b < lim; b <<= 1) {
        for(int i = b; i < lim; ++i) {
            C[i] += C[i - b];
            if(C[i] >= MOD) C[i] -= MOD;
        }
    }
    cin >> T;
    while(T--) {
        cin >> N;
        if(N < lim) {
            cout << C[N] << '\n';
        }
        else {
            cout << 65 << '\n';
        }
    }
}