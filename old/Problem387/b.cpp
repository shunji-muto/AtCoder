#include <iostream>
#include <math.h>


using namespace std;

int main()
{
    int X;
	cin >> X;

    int result = 0;
    for(int i=1; i<=9; ++i){
        for(int j=1; j<=9; ++j){
            if(i*j != X) result += i*j;
        }
    }

    cout << result << endl;
}
