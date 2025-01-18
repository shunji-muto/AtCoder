#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main()
{
    long long count;
	cin >> count;

    deque<long long> snake_heads;
    deque<long long> snake_length;
    
    long long total_sum=0;
    long long total_substruct=0;

    for(int i=0; i<count; i++){
        int query;
        cin >> query;

        if(query==1){
            int l;
            cin >> l;
            snake_length.push_back(l);
            snake_heads.push_back(total_sum);
            total_sum += l;
        }
        else if(query==2){
            total_substruct += snake_length[0];
            snake_length.pop_front();
            snake_heads.pop_front();
        }
        else if(query==3){
            int k;
            cin >> k;
            cout << snake_heads[k-1]-total_substruct << endl;
        }        
    }
}
