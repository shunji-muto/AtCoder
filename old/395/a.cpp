#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=1; i<N; i++){
        if(A[i-1] >= A[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
