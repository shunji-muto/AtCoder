#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<long long> P(N);
    for(long long i=0; i<N; ++i){
        cin >> P[i];
    }
    
    vector<long long> Q(N);
    vector<pair<long long, long long>> zekken_target(N);
    for(long long i=0; i<N; ++i){
        cin >> Q[i];
        zekken_target[i] = make_pair(Q[i], P[i]);
    }
    sort(zekken_target.begin(), zekken_target.end());

    for(long long i=0; i<N; ++i){
        cout << Q[zekken_target[i].second-1] << " ";
    }

    cout << endl;

    return 0;
}
