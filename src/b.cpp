#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;


int main() {
    int num;
    cin >> num;

    vector<vector<char>> N(num, vector<char>(num, '.'));
    vector<vector<char>> E(num, vector<char>(num, '.'));
    vector<vector<char>> S(num, vector<char>(num, '.'));
    vector<vector<char>> W(num, vector<char>(num, '.'));
    rep(i, num){
        rep(j, num){
            char c; cin >> c;
            if(c == '.') continue;
            N[j][i] = '#';
            E[num-1-i][j] = '#';
            S[num-1-j][num-1-i] = '#';
            W[i][num-1-j] = '#';
        }
    }

    int countN = 0;
    int countE = 0;
    int countS = 0;
    int countW = 0;
    rep(i, num){
        rep(j, num){
            char c; cin >> c;
            
            if(N[j][i] != c) countN++;
            if(E[j][i] != c) countE++;
            if(S[j][i] != c) countS++;
            if(W[j][i] != c) countW++;
        }
    }
    countE += 1;
    countS += 2;
    countW += 3;
    int ans = min({countN, countE, countS, countW});

    cout << ans << endl;
  
  return 0;
} 