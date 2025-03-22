#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    pair<int, int > taka;

    string S;
    cin >> N >> taka.first >> taka.second >> S;

    pair<int,int> fire = {0, 0};
    set<pair<int,int>> smoke;
    smoke.insert(fire);
    for(int i=0; i<N; i++){
        if(S[i] == 'N'){
            taka.first++;
            fire.first++;
        }
        else if(S[i] == 'S'){
            taka.first--;
            fire.first--;
        }
        else if(S[i] == 'W'){
            taka.second++;
            fire.second++;
        }
        else if(S[i] == 'E'){
            taka.second--;
            fire.second--;
        }
        smoke.insert(fire);
        if(smoke.find(taka) == smoke.end()) cout << "0";
        else cout << "1";
    }

    cout << endl;

    return 0;
}