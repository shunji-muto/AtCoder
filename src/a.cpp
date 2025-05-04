#include <iostream>
// #include <math.h> // 不要なのでコメントアウト
#include <vector> // vectorを使用するため追加
#include <string>  // stringを使用するため追加
#include <cctype> // isalnumを使用するため追加
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    string s; 
    cin >> s; 

    vector<bool> appeared(256, false);

    for (char c : s) {
            appeared[c] = true;
    }

    for (int i = 97; i < 123; ++i) {
        if (!appeared[i]) {
            cout << (char)i << endl;
            return 0;
        }
    }

    return 0;
}
