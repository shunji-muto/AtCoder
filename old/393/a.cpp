#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    string S1, S2;
    cin >> S1 >> S2;

    if(S1 == "fine"){
        if(S2=="fine") cout << 4 << endl;
        else cout << 3 << endl;
    }
    else{
        if(S2=="fine") cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}
