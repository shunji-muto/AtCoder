#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;





void D169()
{
	long long N;
	cin >> N;

	map<long long, int> m;
	for (long long i = 2; i*i<=N; i+=1)
	{
		while (N%i == 0)
		{
			if (m.count(i) == 0) m.insert(make_pair(i, 1));
			else ++m[i];
			N /= i ;
		}
	}
	if (N != 1 && m.count(N) == 0) m.insert(make_pair(N, 1));

	int cnt = 0;
	for (auto x : m)
	{
		int d = 1;
		while(x.second - d >= 0)
		{
			x.second -= d;
			++d;
			++cnt;
		}
	}
	cout << cnt << endl;
}

void C169()
{
	long long A;
	double B;
	cin >> A >> B;

	long long iB = B*100+0.5;
	long long ans = A * iB /100;
	cout << ans << endl;
}

void B169()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	bool isZero = false;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (A[i] == 0) isZero = true;
	}

	if (isZero)
	{
		cout << "0" << endl;
		return;
	}

	long long ans=1;
	for (int i = 0; i < N; ++i)
	{
		if (A[i] <= 1000000000000000000 / ans) ans *= A[i];
		else
		{
			cout << "-1" << endl;
			return;
		}
	}
	cout << ans << endl;
}

void A169()
{
	int A, B;
	cin >> A >> B;

	cout << A * B << endl;
}

void C_160()
{
  long long K, N;
  cin >> K >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  int max = 0;
  int ans = 0;
  for (int i = 0; i < N; ++i)
  {
    int diff;
    if (i == N - 1) diff = K+A[0] -A[i];
    else            diff = A[i + 1] - A[i];
    
    ans += diff;
    if (max < diff) max = diff;
  }

  ans -= max;
  cout << ans << endl;
}

void B_160()
{
  long long X;
  cin >> X;

  long long ans = 0;
  ans += (X / 500) * 1000;
  X -= (X / 500) * 500;
  ans += (X / 5)*5;

  cout << ans << endl;
}

void A_160()
{
  string S;
  cin >> S;

  if (S[2] == S[3] && S[4] == S[5])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
