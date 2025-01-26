#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long double> a;
    for(int i = 0; i < N; i++){
        int a_in;
        cin >> a_in;
        a.push_back(a_in);
    } 

    long double diff = a[1]/a[0];

    for(int i = 0; i < N-1; i++) {
         if(a[i]*diff != a[i+1]) {
             cout << "No" << endl;
             return 0;
         }
    }

    cout << "Yes" << endl;
}
