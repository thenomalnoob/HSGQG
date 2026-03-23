#include <bits/stdc++.h>
#define NAME "PHONELIST"
#define lim 100000
using namespace std;
int t, n;
string S;
struct trie {
    int child[lim][10], sz;
    bool is_end[lim];
    bool add_prefix(string &S) {
        int u = 0;
        bool exist = 1;
        for(char c : S) {
            int k = c - '0';
            if(!child[u][k]) {
                child[u][k] = ++sz;
                exist = 0;
            }
            u = child[u][k];
        }
        is_end[u] = 1;
        return exist;
    }
    bool exist(string &S) {
        int u = 0;
        for(char c : S) {
            int k = c - '0';
            if(!child[u][k]) {
                return 0;
            }
            u = child[u][k];
        }
        return is_end[u];
    }
    bool exist_prefix(string &S) {
        int u = 0;
        for(char c : S) {
            int k = c - '0';
            if(!child[u][k]) {
                return 0;
            }
            u = child[u][k];
            if(is_end[u]) {
                return 1;
            }
        }
        return is_end[u];
    }
} dict;
void program() {
    memset(&dict, 0, sizeof dict);
    bool flag = 0;
    cin >> n;
    while(n--) {
        cin >> S;
        flag |= dict.exist_prefix(S) | dict.add_prefix(S);
    }
    cout << (flag ? "NO" : "YES") << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--) {
        program();
    }
}