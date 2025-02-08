#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<bool> a(N, false);
    for(int i=0; i<M; ++i){
        int input;
        cin >> input;
        a[input]=true; 
    }

    int count = 0;
    string result = "";
    for(int i=1; i<=N; ++i){
        if(a[i] == false){
            result += to_string(i) + " ";
            ++count;
        } 
        
    }

    if(count == 0) cout << "0" << endl;
    else{
        cout << count << endl;
        cout << result << endl;
    }

    return 0;
}
