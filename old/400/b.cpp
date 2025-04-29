#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    const ll MAX = 1000000000;
    
    // N = 1の場合は簡単に計算可能
    if (N == 1) {
        cout << M + 1 << endl;
        return 0;
    }
    
    // Xが10^9を超えるかどうかを早めにチェック
    if (N >= MAX || M >= 30) {
        cout << "inf" << endl;
        return 0;
    }
    
    ll sum = 1;  // N^0 = 1
    ll current = 1;
    
    for (int i = 1; i <= M; i++) {
        // オーバーフローチェック
        if (current > MAX / N) {
            cout << "inf" << endl;
            return 0;
        }
        
        current *= N;
        if (sum > MAX - current) {
            cout << "inf" << endl;
            return 0;
        }
        
        sum += current;
        if (sum > MAX) {
            cout << "inf" << endl;
            return 0;
        }
    }
    
    cout << sum << endl;
    return 0;
}
