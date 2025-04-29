#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    // 各料理に使用される食材を管理
    vector<vector<int>> dishes(M);
    // 各食材がどの料理で使用されているかを管理
    vector<vector<int>> ingredient_to_dishes(N);
    // 各料理に含まれる苦手な食材の数
    vector<int> bad_ingredients_count(M);
    
    // 各料理の食材情報を入力
    rep(i, M) {
        int K;
        cin >> K;
        bad_ingredients_count[i] = K;  // 最初は全ての食材が苦手
        rep(j, K) {
            int A;
            cin >> A;
            A--;  // 0-indexedに変換
            dishes[i].push_back(A);
            ingredient_to_dishes[A].push_back(i);  // 食材Aを使用する料理iを記録
        }
    }
    
    // 克服する食材の順序を入力
    vector<int> B(N);
    rep(i, N) {
        cin >> B[i];
        B[i]--;  // 0-indexedに変換
    }
    
    // 各日の結果を計算
    int current_edible = 0;  // 現在食べられる料理の数
    rep(day, N) {
        // その日に克服する食材が使われている全ての料理について
        int target = B[day];
        for (int dish : ingredient_to_dishes[target]) {
            bad_ingredients_count[dish]--;
            if (bad_ingredients_count[dish] == 0) {
                current_edible++;  // 新しく食べられるようになった料理
            }
        }
        cout << current_edible << endl;
    }
    
    return 0;
}