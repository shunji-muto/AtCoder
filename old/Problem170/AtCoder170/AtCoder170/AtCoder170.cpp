#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<set>
#include<map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<char> c(N);
	int r_cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> c[i];
		if (c[i] == 'R') ++r_cnt;
	}

	int r=0;
	for (int i = 0; i < r_cnt; ++i)
	{
		if (c[i] == 'R') ++r;
	}

	cout << r_cnt - r << endl;

}

void C174()
{
	int K;
	cin >> K;
	int x = 7%K;
	set<int> s;
	int i = 1;
	while (s.count(x) == 0)
	{
		if (x == 0)
		{
			cout << i << endl;
			return;
		}
		s.insert(x);
		x = (x * 10 + 7) % K;
		++i;
	}
	cout << -1 << endl;
}

void B174()
{
	long long N, D;
	cin >> N >> D;
	
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		long long X, Y;
		cin >> X;
		cin >> Y;
		if (X * X + Y * Y <= D * D) ans++;
	}
	cout << ans << endl;
}

void A174()
{
	int X;
	cin >> X;

	if (X > 29) cout << "Yes" << endl;
	else cout << "No" << endl;
}

void D173()
{
	long long N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A.rbegin(), A.rend());

	long long sum=0;
	int t = N - 1;
	for (int i = 0; i < A.size(); ++i)
	{
		int lim = 2;
		if (i == 0) lim = 1;
		for (int j = 0; j < lim; ++j)
			if (t > 0)
			{
				sum += A[i];
				--t;
			}
	}
	cout << sum << endl;
}

void C173()
{
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> c(H);
	for (int i = 0; i < H; ++i) cin >> c[i];


	int ans = 0;
	for (int ic = 0; ic < 1 << H; ++ic)
	{
		for (int jc = 0; jc < 1 << W; ++jc)
		{
			int cnt = 0;
			for (int i = 0; i < H; ++i)
			{
				for (int j = 0; j < W; ++j)
				{
					if (ic >> i & 1) continue;
					if (jc >> j & 1) continue;
					if (c[i][j] == '#') ++cnt;
				}
			}
			if (cnt == K) ans++;
		}
	}
	cout << ans << endl;
}		

void B173()
{
	int N;
	cin >> N;
	vector<string> S(N);
	int AC=0, WA=0, TLE=0, RE=0;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];

		if (S[i] == "AC") ++AC;
		else if (S[i] == "WA")++WA;
		else if (S[i] == "TLE")++TLE;
		else if (S[i] == "RE")++RE;
	}
	
	cout << "AC x " << AC << endl;
	cout << "WA x " << WA << endl;
	cout << "TLE x " << TLE << endl;
	cout << "RE x " << RE << endl;
}

void A173()
{
	int N;
	cin >> N;

	int money = 1000;
	while (money - N < 0) {
		money += 1000;
	}
	cout << money - N << endl;
}

void D172()
{
	long long N;
	cin >> N;

	long long sum = 0;
	for (int i = 1; i <= N; ++i)
	{

	}
}

void C172()
{
	int N, M;
	long long K;
	cin >> N >> M >> K;
	vector<long long> A(N), B(M);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];

	vector<long long> a, b;
	a.push_back(0);
	b.push_back(0);
	for (int i = 0; i < N; ++i) a.push_back(a[i] + A[i]);
	for (int i = 0; i < M; ++i) b.push_back(b[i] + B[i]);

	int maxNum = 0, num = M;
	for (int i = 0; i <= N; ++i)
	{
		if (a[i] > K) break;

		while (b[num] > K - a[i])
		{
			--num;
		}
		maxNum = max(maxNum, i + num);
	}

	cout << maxNum << endl;
}

void B172()
{
	string S, T;
	cin >> S >> T;

	int cnt = 0;
	for (int i = 0; i < S.length(); ++i)
		if (S[i] != T[i])++cnt;

	cout << cnt;
}

void A172()
{
	int a;
	cin >> a;

	cout << a + a * a + a * a*a << endl;
}

void D171()
{
	long long N;
	cin >> N;
	vector<long long> A(N);
	vector<long long> cnt(100001);
	long long sum=0;
	for (int i = 0; i < N; ++i) 
	{
		cin >> A[i];
		sum += A[i];
		++cnt[A[i]];
	}
	
	int Q;
	cin >> Q;
	vector<long long> ans(Q);
	for (int i = 0; i < Q; ++i)
	{
		long long B, C;
		cin >> B >> C;

		if (cnt[B] == 0)
		{
			ans[i] = sum;
			continue;
		}

		sum -= (B * cnt[B] + C * cnt[C]);
		cnt[C] += cnt[B];
		cnt[B] = 0;
		sum += C * cnt[C];
		ans[i] = sum;
	}

	for (int i = 0; i < Q; ++i) cout << ans[i] << endl;
}

void C171() {
	long long N;
	cin >> N;

	string name = "";
	while (N)
	{
		--N;
		name += (char)('a' + (N % 26));
		N /= 26;
	}

	reverse(name.begin(), name.end());
	cout << name << endl;
}

void D170()
{
	const int M = 1000005;
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<int> cnt(M);
	for (int i = 0; i < N; ++i)
	{
		if (cnt[a[i]] != 0)
		{
			cnt[a[i]] = 2;
			continue;
		}
		for (int j = a[i]; j < M; j += a[i]) cnt[j]++;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		if (cnt[a[i]] == 1) ans++;
	}
	cout << ans << endl;
}


