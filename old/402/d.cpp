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


int main() {
	int N, M;
	cin >> N >> M;

	map<int, int> cnt;
	ll ans = M * ll(M-1)/2;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		int x = (a+b)%N;
		ans -= cnt[x];
		cnt[x]++;
	}
	cout << ans << endl;
	
	return 0;
}
