#include <bits/stdc++.h>
#define NAME "MUABANCO"
#define lim 2000001
using namespace std;
int N, K, A[lim], del;
long long sum;
vector<int> extreme, merged;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    if(N == 1) return cout << 0, 0;
    for(int i = 1; i <= N; ++i) {
        if(i == 1) {
            if(A[1] < A[2]) {
                extreme.push_back(A[1]);
            }
        }
        else if(i == N) {
            if(A[N - 1] < A[N]) {
                extreme.push_back(A[N]);
            }
        }
        else {
            if(A[i - 1] < A[i] && A[i] > A[i + 1] || A[i - 1] > A[i] && A[i] < A[i + 1]) {
                extreme.push_back(A[i]);
            }
        }
    }
    for(int i = 1; i < extreme.size(); i += 2) {
        sum += extreme[i] - extreme[i - 1];
    }
    for(int i = 2; i < extreme.size(); i += 2) {
        merged.push_back(extreme[i] - extreme[i - 1]);
    }
    del = max(0, int(extreme.size() / 2 - K));
    sort(merged.begin(), merged.end());
    for(int i = 0; i < del; ++i) {
        sum += merged[i];
    }
    cout << sum;
}