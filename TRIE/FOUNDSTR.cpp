#include <bits/stdc++.h>
#define NAME "FOUNDSTRING"
#define lim 500000
using namespace std;
int N;
string S;
struct trie {
    int child[lim][26], sz;
    bool is_end[lim];
    void add(string &S) {
        int u = 0;
        for(char c : S) {
            int k = c - 'a';
            if(!child[u][k]) {
                child[u][k] = ++sz;
            }
            u = child[u][k];
        }
        is_end[u] = 1;
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
    while(N--) {
        cin >> S;
        dict.add(S);
    }
    cin >> N;
    while(N--) {
        cin >> S;
        cout << dict.exist(S) << '\n';
    }
}