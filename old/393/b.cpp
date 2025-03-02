#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    string S;
    cin >> S;

    long long count=0;
    for(int i=0;i<S.length();++i){
        if(S[i] != 'A') continue;
        for(int j=1; j+j+i<S.length();++j){
            if(S[i+j]=='B' && S[i+j+j]=='C') ++count;
        }
    }

    cout << count << endl;

    return 0;
}
