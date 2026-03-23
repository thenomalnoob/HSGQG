#include <bits/stdc++.h>
#define lim 100001
using namespace std;
int N, sz, u, v;
vector<int> adj[lim];
int deg[lim];
queue<int> rem_q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    for(int i = 1; i <= N; ++i) {
        if(deg[i] == 1) {
            rem_q.push(i);
        }
    }
    if(N == 1) {
        return cout << "1\n1", 0;
    }
    while(N > 2) {
        sz = rem_q.size();
        N -= sz;
        while(sz--) {
            int u = rem_q.front();
            rem_q.pop();
            deg[u] = 0;
            for(int v : adj[u]) {
                if(deg[v]) {
                    if(--deg[v] == 1) {
                        rem_q.push(v);
                    }
                    break;
                }
            }
        }
    }
    if(rem_q.size() == 1) {
        cout << '1' << '\n' << rem_q.front();
    }
    else {
        u = rem_q.front();
        rem_q.pop();
        v = rem_q.front();
        cout << '2' << '\n' << min(u, v) << '\n' << max(u, v); 
    }
}
