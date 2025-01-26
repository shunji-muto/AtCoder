#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> S;
    for(int i = 0; i < H; i++) {
        string S_in;
        cin >> S_in;
        S.push_back(S_in);
    }

    //黒領域の上下左右の座標を求める
    int bt=H, bb=0, bl=W, br=0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                if(bt > i) bt = i;
                if(bb < i) bb = i;
                if(bl > j) bl = j;
                if(br < j) br = j;
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.') {
                if((bt <= i && bb >= i) && (bl <= j  && br >= j)){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
}
