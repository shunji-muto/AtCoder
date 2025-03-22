#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    vector<int> Card(13,0);
    for(int i=0; i<7; i++){
        int A;
        cin >> A;

        Card[A-1]++;
    }

    int avobe_three = 0;
    int two_card = 0;
    for(int i=0; i<13; i++){
        if(Card[i] >= 3) avobe_three++;
        if(Card[i] == 2) two_card++;
    }

    if((avobe_three >= 2) || (avobe_three == 1 && two_card >= 1)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
