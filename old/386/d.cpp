#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, char>> points;
    for(int i=0; i<M; i++){
        int x,y;
        char c;
        cin >> x >> y >> c;
        points.emplace_back(x,y,c);
    }
    sort(points.rbegin(), points.rend());

    int max_y=-1;
    for(auto [x,y,c]: points){
        if(c=='B'){
            max_y = max(max_y, y);
        }
        else{
            if(y <= max_y){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
