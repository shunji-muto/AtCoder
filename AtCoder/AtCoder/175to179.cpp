#include "cppfile.h"

void A177()
{
	int d, t, s;
	cin >> d >> t >> s;

	if ((float)d / s > t) cout << "No" << endl;
	else cout << "Yes" << endl;
}

void B177()
{
	string s, t;
	cin >> s >> t;

	int itr = s.length() - t.length() + 1;
	int min_cost = s.length();

	for (int i = 0; i < itr; ++i)
	{
		int cost = 0;
		for (int j = 0; j < t.length(); ++j)
		{
			if (s[i + j] != t[j])  ++cost;
		}

		if (min_cost > cost) min_cost = cost;
	}

	cout << min_cost << endl;
}

void C177()
{
	int mod = 1000000007;
	int n;
	cin >> n;

	long long sum = 0;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
		sum %= mod;
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		sum -= a[i];
		if (sum <= 0)sum += mod;

		ans += sum * a[i];
		ans %= mod;
	}

	cout << ans << endl;
}

void A176()
{
	int N, X, T;
	cin >> N >> X >> T;


	int ans;
	if ((float)N / X > N / X) ans = (N / X + 1) * T;
	else ans = N / X * T;

	cout << ans << endl;
}

void B176()
{
	string N;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N.length(); ++i)
	{
		sum += N[i] - '0';
	}

	if (sum % 9 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

}

void C176()
{
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	long long ans = 0;
	for (int i = 1; i < N; ++i)
	{
		if (A[i - 1] > A[i])
		{
			ans += A[i - 1] - A[i];
			A[i] = A[i - 1];
		}
	}

	cout << ans << endl;
}

void D176()
{
	int H, W;
	cin >> H >> W;

	int Ch, Cw, Dh, Dw;
	cin >> Ch >> Cw >> Dh >> Dw;
	Ch--; Cw--; Dh--; Dw--;

	int Dpos = Dh * W + Dw;
	vector<string> S(H);
	for (int i = 0; i < H; ++i) cin >> S[i];

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<bool> done(H*W);
	pq.push(make_pair(0, Ch * W + Cw));
	while (!pq.empty())
	{
		auto x = pq.top();
		pq.pop();

		int cost = x.first;
		int pos = x.second;
		if (done[pos]) continue;
		done[pos] = true;
		if (pos == Dpos)
		{
			cout << cost << endl;
			return;
		}

		int ph = pos / W;
		int pw = pos % W;
		int dirs[4][2] =
		{
			{-1,0},
			{0,-1},
			{1,0},
			{0,1}
		};

		for (auto & dir : dirs)
		{
			int nh = ph + dir[0];
			int nw = pw + dir[1];
			if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

			int npos = nh * W + nw;
			if (done[npos]) continue;
			if (S[nh][nw] == '#') continue;
			pq.push(make_pair(cost, npos));

		}

		for (int i = -2; i <= 2; ++i)
		{
			for (int j = -2; j <= 2; ++j)
			{
				int nh = ph + i;
				int nw = pw + j;

				if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
				int npos = nh * W + nw;
				if (done[npos]) continue;
				if (S[nh][nw] == '#') continue;
				pq.push(make_pair(cost + 1, npos));
			}
		}
	}

	cout << -1 << endl;


}

void A175()
{
	string S;
	cin >> S;

	int count = 0;
	int max = 0;
	for (int i = 0; i < S.length(); ++i)
	{
		if (S[i] == 'R') ++count;
		else
		{
			if (max < count) max = count;
			count = 0;
		}
	}

	if (max < count)max = count;

	cout << max << endl;
}

void B175()
{
	int N;
	cin >> N;

	vector<int> L(N);
	for (int i = 0; i < N; ++i) cin >> L[i];
	sort(L.begin(), L.end());

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (L[j] == L[i]) continue;
			for (int k = j + 1; k < N; ++k)
			{
				if (L[k] == L[j]) continue;
				if (L[i] + L[j] > L[k]) ++count;
			}
		}
	}
	cout << count << endl;
}

void C175()
{
	long long X, K, D;
	cin >> X >> K >> D;

	X = abs(X);
	long long div = X / D;
	if (div > K)
	{
		X -= K * D;
	}
	else
	{
		X -= div * D;

		K -= div;
		if (K % 2 == 1)  X -= D;
	}

	cout << abs(X) << endl;
}

void D175()
{
	int N;
	long long K;
	cin >> N >> K;

	vector<int>P(N);
	vector<long long> C(N);
	long long cycle_sum = 0;
	for (int i = 0; i < N; ++i) cin >> P[i];
	for (int i = 0; i < N; ++i)
	{
		cin >> C[i];
		cycle_sum += C[i];
	}
	cout << "cycle_sumF" << cycle_sum << endl;

	long long max_score;
	bool is_first = false;
	for (int i = 0; i < N; ++i)
	{
		if (is_first == false)
		{
			is_first = true;
			max_score = C[i];
		}

		long long sum = 0;
		int now = P[i] - 1;
		for (int j = 0; j < K%N; ++j)
		{
			sum += C[now];
			now = P[now] - 1;
			max_score = max(sum, max_score);
		}
	}
	cout << "cycle_sum*numF" << (K / N) * cycle_sum << endl;
	cout << "max_scoreF" << max_score << endl;

	long long total_score = 0;
	if (cycle_sum > 0) total_score = (K / N) * cycle_sum + max_score;
	else total_score = max_score;

	cout << total_score << endl;
}