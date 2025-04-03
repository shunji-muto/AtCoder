#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int N;
ll ans = 2e18;

void dfs(int v, vector<vector<pair<int, ll>>> &G, vector<bool> &visited, ll x){
    visited[v] = true;
    for(auto next : G[v]){
        if(v == N-1) ans = min(ans, x);
        if(visited[next.first]) continue;
        dfs(next.first, G, visited, x^next.second);
    }
    visited[v] = false;
    return;
}

int main()
{
    int M, u, v; ll w;
    cin >> N >>M;

    vector<vector<pair<int, ll>>> G(N);
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }

    vector<bool> visited(N, false);
    dfs(0, G, visited, 0);    

    cout << ans << endl;

    return 0;
}
