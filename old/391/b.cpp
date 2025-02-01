#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    vector<string> S(N+M);
    for(int i = 0; i < N+M; i++) {
        cin >> S[i];
    }

    int count = 0;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == S[N][0]){
                for(int k = 0; k < M; k++) {
                    for(int l = 0; l < M; l++) {
                        if(S[i+k][j+l] == S[N+k][l]){
                            count++;
                            if(count == M*M) cout << (i+1) << " " << (j+1) << endl;
                        }
                        else{
                            flag = true;
                            break;
                        }
                    }
                    if(flag) {
                        count = 0;
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
