#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    int A;
    cin >> A;

    if(400%A == 0){
        cout << 400/A << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
