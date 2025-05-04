#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<set<int>> authority(N);
    vector<bool> allAuthority(N, false);

    vector<ll> A(N, 0);
    
    rep(i, Q) {
        int query; cin >> query;
        if(query == 1) {
            int x, y; cin >> x >> y;
            x--;y--;
            authority[x].insert(y);
        }
        else if(query == 2){
            int x; cin >> x;
            x--;
            allAuthority[x] = true;
        }
        else if(query == 3){
            int x, y; cin >> x >> y;
            x--; y--;
            if( authority[x].count(y) || allAuthority[x]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}