#include <bits/stdc++.h>

using namespace std;

long long int_pow(long long x, long long y){
    long long result = 1;
    for(int i=0;i<y;i++) result *= x;
    return result;
}

long long Calc(long long r){
    vector<int> digit;
    while (r) {//つまりポイント
        digit.push_back(r % 10);
        r /= 10;
    }
    reverse(digit.begin(), digit.end());

    int len = digit.size();
    long long result = 0;
    for(int i=1;i<=len;i++){
        if(i==len){
            result++;
            break;
        }
        result += int_pow(digit[0], len-1-i )* min(digit[0], digit[i]);
        if(digit[0] <= digit[i]) break;
    }

    for(int i=0;i<len;i++){
        int max = (i ? 9 : digit[0]-1);
        for(int j=1;j<=max;j++){
            result += int_pow(j, len-1-i);
        }
    }

    return result;
}

int main()
{
    long long L, R;
	cin >> L >> R;

    cout << Calc(R)-Calc(L-1) << endl;
}
