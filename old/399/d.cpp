#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i=0; i<T; ++i){
        int N;
        cin >> N;
        
        vector<int> A(2*N);
        for(int j=0; j<2*N; ++j){
            cin >> A[j];
            --A[j];
        }
        
        vector<vector<int>> Pos(N);
        for(int j=0; j<2*N; ++j) Pos[A[j]].emplace_back(j);

        set<pair<int, int>> P;
        for(int j=0; j+1<2*N; ++j){
            int a = A[j], b = A[j+1];
            if(Pos[a][0] +1 == Pos[a][1]) continue;
            if(Pos[b][0] +1 == Pos[b][1]) continue;

            vector<int> v{Pos[a][0], Pos[a][1], Pos[b][0], Pos[b][1]};
            sort(v.begin(), v.end());
            if(v[0] +1 == v[1] && v[2] +1 == v[3]){
                P.emplace(minmax(a,b));
            }
        }
        cout << P.size() << endl;

    }
    return 0;
}


