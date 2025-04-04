#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i=0; i<n; ++i)


using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
ll a;
    vector<int> p2b(N);
    vector<int> b2h(N);
    vector<int> h2b(N);
    rep(i, N){
        p2b[i] = i;
        b2h[i] = i;
        h2b[i] = i;
    }

    rep(i, Q){
        int operation;
        cin >> operation;

        if(operation == 1){
            int a, b;
            cin >> a >> b;
            a--; b--;

            p2b[a] = h2b[b];
        }
        else if(operation == 2){
            int a, b;
            cin >> a >> b;
            a--; b--;

            swap(h2b[a], h2b[b]);
            swap(b2h[h2b[a]], b2h[h2b[b]]);
        }
        else{
            int a;
            cin >> a;
            a--;

            cout << b2h[p2b[a]]+1 << '\n';
        }
    }
    return 0;
}


