#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    int N;
    cin >> N;  // Nを標準入力で受け取る
    
    vector<int> A(N);  // サイズNの配列を定義
    for(int i = 0; i < N; i++){
        cin >> A[i];  // N回分の入力を配列に格納
    }
    
    // 偶数番目の要素の総和を計算
    int sum = 0;
    for(int i = 0; i < N; i += 2){  // i を 2 ずつ増やして偶数番目のみ処理
        sum += A[i];
    }
    
    cout << sum << endl;  // 偶数番目の総和を出力
    
    return 0;
}
