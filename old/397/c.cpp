#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<long long> A(N);
    for(long long i=0; i<N; i++){
        cin >> A[i];
    }


    long long left_count = 0;
    long long right_count = 0;
    vector<bool> left_flag(N, false);
    vector<bool> right_flag(N, false);
    vector<long long> left_counts(N);
    vector<long long> right_counts(N);
    for(long long i=0; i<N; i++){
        if(left_flag[A[i]] == false){
            left_flag[A[i]] = true;
            left_count++;
        }
        if(right_flag[A[N-1-i]] == false){
            right_flag[A[N-1-i]] = true;
            right_count++;
        }
        left_counts[i] = left_count;
        right_counts[N-1-i] = right_count;
    }

    long long max = 0;
    for(long long i=0; i<N-1; i++){
        if(left_counts[i]+ right_counts[i+1] > max) max = left_counts[i]+ right_counts[i+1];
    }
    cout << max << endl;

    return 0;
}
