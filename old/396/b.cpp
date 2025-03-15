#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int Q;
    cin >> Q;

    stack<int> s;
    for(int i=0; i<Q; i++){
        int query;
        cin >> query;

        if(query == 1){
            int x;
            cin >> x;
            s.push(x);
        }
        else{
            if(s.empty()){
                cout << 0 << endl;
            }
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
    }
    
    return 0;
}
