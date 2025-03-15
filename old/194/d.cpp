#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    cin >> N;

    double ans = 0;
    for(int i=1; i<N; ++i){
        ans +=  1.0 *  N / (N-i);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
