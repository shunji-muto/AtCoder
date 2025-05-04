#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;


int main() {
    string T, U;
    cin >> T >> U;
    
    for(int i = 0; i < T.size(); ++i){
        int count = 0;
        for(int j = 0; j < U.size(); ++j){
            if(T[i+j] == U[j] || T[i+j] == '?') count++;
            else break;
        }
        if(count == U.size()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
} 