#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int cnt = 0;


void dfs(int v, vector<vector<int>> &G, vector<bool> &visited) {
    ++cnt;
    visited[v] = true;
    for(auto nv : G[v]) {
        if(visited[nv]) continue;
        dfs(nv, G, visited);
    }
}

int main()
{
    int N, M;
    cin >> N >> M ;

    if(N != M) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> A(N, 0);
    vector<vector<int>> G(N);
    rep(i,M){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);

        A[a]++;
        A[b]++;
        if(A[a] > 2 || A[b] > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<bool> visited(N, false);
    dfs(cnt, G, visited);

    if(cnt != N) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}