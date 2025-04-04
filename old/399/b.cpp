#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int,int>> P;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        P.emplace_back(x,i);
    }

    sort(P.rbegin(), P.rend());
    vector<int> Rank(N);
    int r = 1;
    int count = 0;
    Rank[P[0].second] = r;
    for(int i=1; i<N; i++){
        if(P[i].first == P[i-1].first){
            Rank[P[i].second] = r;
            count++;
        }
        else{
            r += count + 1;
            count = 0;
            Rank[P[i].second] = r;
        }
    }

    for(int i=0; i<N; i++){
        cout << Rank[i] << endl;
    }

    return 0;
}
