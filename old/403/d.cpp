#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
#include <iostream>
#include <numeric>
#include <cstdint>
#include <limits>

int solve(vector<int> a) {
	int n = a.size();
	vector<vector<int>> dp(n+1, vector<int>(2, 0));
	for(int i = 0; i < n; i++) {
		dp[i+1][0] = max(dp[i][0], dp[i][1]);
		dp[i+1][1] = dp[i][0] + a[i];
	}
	int mx = max(dp[n][0], dp[n][1]);
	int sum = 0;
	rep(i, n) sum += a[i];
	return sum - mx;
}
int main() {
	int N, D;
	cin >> N >> D;
	
	int M = 1000005;
	vector<int> count(M, 0);
	rep(i, N) {
		int a; cin >> a;
		count[a]++;
	}
	
	int ans = 0;
	if(D==0){
		rep(i, M) {
			if(count[i] > 0) ans += count[i]-1;
		}
	}else{
		rep(j, D) {
			vector<int> a;
			for(int i = j; i < M; i += D) {
				a.push_back(count[i]);
			}

			ans += solve(a);
		}
	}
	cout << ans << endl;
	return 0;
}
