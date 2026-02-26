#include <bits/stdc++.h>
#define NAME "BTS"
#define lim 200001
using namespace std;
int n, h[lim];
long long cnt, L[lim];
vector<int> st;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        while(!st.empty() && st.back() < h[i]) st.pop_back(), ++cnt;
        if(!st.empty()) ++cnt;
        while(!st.empty() && st.back() == h[i]) st.pop_back();
        st.push_back(h[i]);
    }
    cout << cnt;
}
//9 4 5 1 10 9
//9 4 -> 1
//9 4 5