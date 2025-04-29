#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> que;

    for(int i=0; i<N; i++){
        int query;
        cin >> query;

        if(query==1){
            int num;
            cin >> num;
            que.push(num);
        }
        else if(query==2){
            cout << que.front() << endl;
            que.pop();

        }
    }
    

    return 0;
}
