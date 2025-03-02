#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int min_length = N+1;
    vector<int> A(1000000, 0);
    for(int i=0; i<N; i++){
        int value;
        cin >> value;


        if(A[value] <= 0){
            A[value] = i+1;
        } 
        else{ 

            int length = i+1 - A[value]+1;
            if(length < min_length){
                min_length = length;
            }
            
            A[value] = i+1;
        }
    }

    if(min_length == N+1) {
        cout << -1 << endl;
        return 0;
    }
    cout << min_length << endl;
    return 0;
}
