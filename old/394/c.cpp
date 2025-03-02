#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    for(int i=n-1; i>0; i--){
        if(S[i] == 'A' && S[i-1] == 'W'){
            S[i] = 'C';
            S[i-1] = 'A';
        }
    }
    cout << S << endl;
    return 0;
}
