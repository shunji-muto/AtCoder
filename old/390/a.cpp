#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a[5];
    for(int i = 0; i < 5; i++) cin >> a[i];

    int count = 0;
    for(int i = 0; i < 5; i++) {
        if(a[i] == i+2 && a[i+1] == i+1) {
            count++;
            i++;
        }
        else if (a[i] == i+1) {
            continue;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }

    if(count == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

}
