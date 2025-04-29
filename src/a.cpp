#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    string S;
    cin >> S;

    string ans="";
    for(int i=0; i<S.size(); i++){
        if(S[i]>='A' && S[i]<='Z'){ans+=S[i];}
    }

    cout << ans << endl;
    return 0;
}
