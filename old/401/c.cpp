#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1);
    vector<int> S(N+2);

    if(N<K){
        cout << 1 << endl;
        return 0;
    }

    rep(i, K) A[i] = 1;
    rep(i, K) S[i+1] = S[i] + A[i];

    const ll MOD = 1e9;
    for(int i=K; i<=N; ++i){
        A[i] = (S[i] - S[i-K] + MOD) % MOD;
        S[i+1] = (S[i] + A[i]) % MOD;
    }

    cout << A[N] << endl;
}