#include "cppfile.h"

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