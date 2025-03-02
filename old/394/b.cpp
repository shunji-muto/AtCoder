#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;
bool compare(string & s1, string& s2) {return s1.size() < s2.size();}

int main()
{
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i=0; i<N; ++i){
        cin >> S[i];
    }
    sort(S.begin(), S.end(), compare);

    for(int i=0; i<N; ++i){
        cout << S[i];
    }

    cout << endl;

    return 0;
}
