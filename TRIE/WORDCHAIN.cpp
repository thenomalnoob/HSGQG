#include <bits/stdc++.h>
#define NAME "WORDCHAIN"
#define lim 250001
using namespace std;
int N, max_chain;
string S;
vector<string> v;
struct trie {
    int child[lim][26], sz;
    bool is_end[lim];
    int add(string &S) {
        int u = 0, cnt = 0;
        for(char c : S) {
            int k = c - 'a';
            if(!child[u][k]) {
                child[u][k] = ++sz;
            }
            u = child[u][k];
            cnt += is_end[u];
        }
        is_end[u] = 1;
        return ++cnt;
    }
    bool exist(string &S) {
        int u = 0;
        for(char c : S) {
            int k = c - 'a';
            if(!child[u][k]) {
                return 0;
            }
            u = child[u][k];
        }
        return is_end[u];
    }
} dict;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N;
    v.resize(N + 1);
    for(int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= N; ++i) {
        max_chain = max(max_chain, dict.add(v[i]));
    }
    cout << max_chain;
}
