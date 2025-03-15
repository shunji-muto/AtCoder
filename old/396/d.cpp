#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>>  G(M);
    for(int i=0; i<M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    long long ans = 1 << 60;
    vector<bool> visited(N, false);

    function<void(int, long long)> dfs = [&](int u, long long w){
        if(u == N-1){
            ans = min(ans, w);
            return;
        }

        visited[u] = true;
        for(auto [v, w2]: G[u]){
            if(visited[v]) continue;
            dfs(v, w+w2);
        }
        visited[u] = false;
    };

    cout << "No" << endl;

    return 0;
}
