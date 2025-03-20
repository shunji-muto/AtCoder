#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    string S;
    cin >> S;

    bool flag = false;
    if(S[0] == 'o'){
        S = "i"+S;
        flag = true;
    } 

    int count = 0;
    for(int i=0; i<S.size()-1; i++){
        if(S[i] == S[i+1]) count++;
    }
    if(( count + S.size() ) % 2 == 1) count++;

    if(flag) count++;
    cout << count << endl;
    return 0;
}
