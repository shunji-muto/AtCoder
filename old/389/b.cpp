#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long X;
	cin >> X;

    long long num = 2;
    while(1){
        X=X/num;
        if(X==1) break;
        num++;
    }

    cout << num << endl;

}
