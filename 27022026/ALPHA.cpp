#include <bits/stdc++.h>
#define NAME "ALPHA"
#define lim 1000001
using namespace std;
int M, t, k, a, b, mp[lim], tmp, tmc, cnt_p[lim], fake_N;
long long res;
vector<int> prime;
void priminit() {
    for(int i = 2; i * i < lim; ++i)
        if(!mp[i])
            for(int j = i * i; j < lim; j += i)
                mp[j] = i;
    prime.push_back(2), mp[2] = 2;
    for(int i = 3; i < lim; i += 2) if(!mp[i]) prime.push_back(i), mp[i] = i;
}
inline int power(long long a, int b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % M;
        b >>= 1;
        a = a * a % M;
    }
    return res;
}
inline int power2(long long a, int b) {
    long long res = 1;
    while(b--) {
        res = res * a % M;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    priminit();
    cin >> M >> t;
    while(t--) {
        cin >> k;
        if(k == 1) {
            cin >> a >> b;
            while(mp[a]) {
                tmp = mp[a], tmc = 0;
                while(mp[a] == tmp) a /= tmp, ++tmc;
                cnt_p[tmp] += tmc * b;
            }
        }
        else if(k == 2) {
            cin >> a >> b;
            while(mp[a]) {
                tmp = mp[a], tmc = 0;
                while(mp[a] == tmp) a /= tmp, ++tmc;
                cnt_p[tmp] -= tmc * b;
            }
        }
        else {
            tmp = 0, res = 1;
            for(int p : prime) 
                if(cnt_p[p]) tmp = __gcd(tmp, cnt_p[p]);
            if(!tmp) {
                tmp = 1;
            }
            else if(tmp == 1) {
                for(int p : prime)
                    if(cnt_p[p]) res = res * power(p, cnt_p[p]) % M;
            }
            else {
                for(int p : prime)
                    if(cnt_p[p]) res = res * power(p, cnt_p[p] / tmp) % M;
            }                          
            cout << res << ' ' << tmp << '\n';
        }
    }
}