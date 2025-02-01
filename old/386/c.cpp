#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int K;
    string S,T;
    cin >> K >> S >> T;

    int s_size = S.size();
    int t_size = T.size();

for(int i=0,j=0; i<s_size && j<t_size; i++,j++){
    if(S[i] == T[j]) continue;
    if(s_size < t_size && i < s_size) i--;
    if(s_size > t_size && j < t_size) j--;
    K--;
}
    if(K>-1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}