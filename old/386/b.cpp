#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int size = S.size();
    int count = 0;
    for(auto i=0; i<size; i++){
        if( char(S.at(i)) == '0') {
            if(i+1 == size) {
                count++;
                continue;
            }
            if(S.at(i+1) == '0') {
                ++i;
            }
        }
        count++;
    }
    cout << count << endl;
    return 0;

}