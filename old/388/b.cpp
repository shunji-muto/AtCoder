#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N,D;
	cin >> N >> D;

    vector<int> T, L;
    for(int i =0; i < N; i++){
        int t_in, l_in;
        cin >> t_in >> l_in;
        T.push_back(t_in);
        L.push_back(l_in);
    }

    vector<int> max(D,0);
    for(int i=0; i<D; ++i){
        for(int j=0; j<N; ++j){
            int weight = T[j]*(L[j]+i+1);
            if(weight > max[i]) max[i] = weight;
        }
    }

    for(int i=0; i<D; ++i){
        cout << max[i] << endl;
    }
}
