#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N;
    cin >> N;


    vector<pair<long long, long long>> A(N);
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        A.emplace_back(x, i+1);
    }
    sort(A.rbegin(), A.rend());

    int result = -1;
    for(int i=0; i<N; i++){
        //最初の時
        if(i==0){
            if(A[i].first != A[i+1].first){
                result = A[i].second;
                break;
            }
        }else if(i==N-1){
            if(A[i].first != A[i-1].first){
                result = A[i].second;
                break;
            }
        }else{
            if(A[i].first != A[i-1].first && A[i].first != A[i+1].first){
                result = A[i].second;
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}
