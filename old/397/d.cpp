#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;

int main()
{
    long long  N;
    cin >> N;

    for(long long d = 1; d*d*d <N; ++d){
        long long c = (N-d*d*d);
        if(c%(3*d)) continue;
        c /= 3*d;
        long long y = (sqrt(d*d+4*c)-d)/2;
        if( (y*y+d*y-c) == 0){
            cout << y+d << " " << y << endl;
            return 0;
        }

    }
    cout << -1 << endl;
    return 0;
}
