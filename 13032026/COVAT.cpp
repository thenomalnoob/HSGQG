#include <bits/stdc++.h>
#define NAME "COVAT"
#define lim 500002
#define MOD 1000000007
using namespace std;
int N, Li, Ri, a[lim], Lmax[lim], Rmax[lim], Lmin[lim], Rmin[lim], cntL, cntR, sumL, sumR, l, add;
long long ans;
vector<int> st;
long long sum(long long l, long long r){
    long long n = r - l + 1;
    return (l + r) % MOD * N % MOD * ((MOD + 1) / 2) % MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N;
    for(Ri = 1; Ri <= N; ++Ri) {
        cin >> a[Ri];
    }
    for(int i = 1; i <= N; ++i) {
        while(!st.empty() && a[st.back()] > a[i]) st.pop_back();
        Lmin[i] = st.empty()? 0 : st.back();
        st.push_back(i);
    }
    st.clear();
    for(int i = N; i; --i) {
        while(!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        Rmin[i] = st.empty()? N + 1 : st.back();
        st.push_back(i);
    }
    st.clear();
    for(int i = 1; i <= N; ++i) {
        while(!st.empty() && a[st.back()] < a[i]) st.pop_back();
        Lmax[i] = st.empty()? 0 : st.back();
        st.push_back(i);
    }
    st.clear();
    for(int i = N; i; --i) {
        while(!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        Rmax[i] = st.empty()? N + 1 : st.back();
        st.push_back(i);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = i;j <= min(Rmin[i] - 1,Rmax[i] - 1);j++){
            int L = max(Lmin[i],Lmax[j]) + 1;
            int R = min(Rmin[i],Rmax[j]) - 1;
            if(L>i || R<j) continue;
            cntL = i - L + 1;
            cntR = R - j + 1;
            sumL = sum(L,i);
            sumR = sum(j,R);
            long long l = (cntR * ((sumR - sumL) % MOD + MOD) % MOD) % MOD;
            long long add = a[i] % MOD * a[j] % MOD % MOD * l % MOD;
            ans = (ans + add) % MOD;
        }
    }
    cout << ans % MOD;
}