#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> adj;
vector<bool> used;

void DFS(ll node){
    used[node] = true;
    cout << node << " ";
    for(auto c : adj[node]){
        if (!used[c]) {
            DFS(c);
        }
    }
}

void solve(){
    ll n, x; 
    cin >> n >> x;

    adj.assign(n + 1, vector<ll>());
    used.assign(n + 1, false);

    for(ll i = 0; i < x; i++){
        ll a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1);

    cout << endl;
    cout << (used[4] && used[5] && used[3] ? "YES" : "NO") << endl;
}