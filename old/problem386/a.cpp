#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int A, B, C, D, t[14]={};
    cin >> A >> B >> C >> D;
    t[A]++;t[B]++; t[C]++; t[D]++;

    int count=0, x=0, y=0;
    for(int i = 1; i <= 13; i++){
        if(t[i]){
            if(++count > 2) return cout << "No", 0;
            if(x) y=i;
            else x=i;
        }
    }
    if(y != 0) return cout << "Yes", 0;
    else return cout << "No", 0;

}