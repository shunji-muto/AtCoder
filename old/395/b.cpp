#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;
bool compare(string & s1, string& s2) {return s1.size() < s2.size();}

int main()
{
    int N;
    cin >> N;

    vector<vector<string>> S(N, vector<string>(N, "#"));

    for(int i=1; i<N; ++i){
        int j = N+1-i;
        for(int is = i-1; is<j; ++is){
            for(int js = i-1; js<j; ++js){
                if(i%2==0) S[is][js] = ".";
                else S[is][js] = "#";
            } 
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << S[i][j];
        }
        cout << endl;
    }
    return 0;
}
