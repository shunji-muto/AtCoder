#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;

    vector<long long> B(N);
    for(long long i=0; i<N; i++){
        cin >> B[i];
    }
    sort(B.begin(), B.end(), [](int a, int b) {return a > b;});

    vector<long long> W(M);
    for(long long  i=0; i<M; i++){
        cin >> W[i];
    }
    sort(W.begin(), W.end(), [](int a, int b) {return a > b;});

    long long ans = 0;
    for(long long i=0; i<B.size(); ++i){
        if(B[i]>=0){
            ans += B[i];
            if(i<W.size() && W[i]>=0) ans += W[i];
        }
        else{
            if(i<W.size() && B[i]+W[i]>=0) {
                ans += B[i] + W[i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
