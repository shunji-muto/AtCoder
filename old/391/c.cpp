#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N,Q;
    cin >> N >> Q;
    vector<long long> bird(N);
    for (long long i = 0; i < N; i++) {
        bird[i] = i;
    }

    vector<long long> nest(N,1);
    long long query;
    long long count = 0;
    for(long long i = 0; i < Q; i++) {
        cin >> query;
        if(query == 1) {
            long long P,H;
            cin >> P >> H;

            if(nest[H-1]+1 == 2) count++;
            nest[H-1] += 1;
            
            if(nest[bird[P-1]]-1 == 1) count--;
            nest[bird[P-1]] -= 1;
            bird[P-1] = H-1; 
        }
        else {
            cout << count << endl;
        }
    }
}
