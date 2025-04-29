#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    ll N;
    cin >> N;

    ll result = 0;
    for(int i =1; i<60; ++i){
        ll m = sqrtl(N/powl(2,i));
        result += (m+1)/2;
    }

    cout << result << endl;
}