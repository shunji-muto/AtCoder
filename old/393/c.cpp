#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;

    long long count=0;
    map<string,long long> pair_int;
    for(long long i=0;i<M;++i){
        long long u,v;
        cin >> u >> v;

        if(u==v){
            count++;
            continue;
        }

        long long b = u > v ? v : u;
        long long t = u > v ? u : v;
        string key = to_string(b)+"-"+to_string(t);
        if(!pair_int.count(key)){
            pair_int[key]=t;
        }
        else{
            if( pair_int[key] != t){
                pair_int[key]=t;
            }
            else{
                ++count;
            }
        } 

    }


    cout << count << endl;

    return 0;
}
