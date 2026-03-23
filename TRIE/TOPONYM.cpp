#include <bits/stdc++.h>
#define NAME "TOPONYM"
#define lim 30000000
using namespace std;
int N, max_complexity;
string S;
vector<string> v;
struct trie {
    int sz, child[lim][26], cnt_visit[lim], depth[lim];
    void add(string &S) {
        int u = 0, cnt = 0;
        for(char c : S) {
            int k = c - 'A';
            if(!child[u][k]) {
                child[u][k] = ++sz;
                /*child.emplace_back(array<int, 26>{});
                cnt_visit.push_back(0);
                depth.push_back(depth[u] + 1);*/
            }
            u = child[u][k];
            ++cnt_visit[u];
            max_complexity = max(max_complexity, cnt_visit[u] * depth[u]);
        }
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
    cout << max_complexity;
}
