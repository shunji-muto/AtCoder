#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;


    int count = 0;
    bool is_login = false;
    rep(i, N){
        string S;
        cin >> S;

        if(S=="login") is_login = true;
        else if(S=="logout") is_login = false;
        else if(S=="private") {
            if(!is_login) count++;
        }
    } 

    cout << count << endl;

    return 0;
}
