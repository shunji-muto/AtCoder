#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N;
	cin >> N;

    vector<long long> A;
    for(int i =0; i < N; i++){
        long long a_in;
        cin >> a_in;
        A.push_back(a_in);
    }

    long long  result = 0;
    for(long long i=0; i<N; ++i){
        long long l=0,r=N-1;
        while(l <= r){
            long long mid = (l+r)/2;
            if(A[i]*2 <= A[mid]) r = mid-1;
            else l = mid+1;
        }
        result += N-l;
    }
    cout << result << endl;
}
