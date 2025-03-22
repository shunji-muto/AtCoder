#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    cin >> N;


    for(int i=0; i<N; i++){
        if(i == ceil(N/2.0)-1){
            cout << "=";
        }
        else if(i == ceil(N/2.0)){
            if(N%2==0) cout << "=";
            else cout << "-";
        }
        else cout << "-";
    }

    cout << endl;

    return 0;
}
