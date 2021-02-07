#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

void C_98()
{
  int N;
  string S;
  cin >> N >> S;

  vector<int> num_W(N, 0), num_E(N, 0);
  
  num_W[0] = (S[0] == 'W') ? 1 : 0;
  num_E[0] = (S[0] == 'E') ? 1 : 0;

  for (int i = 1; i < N; ++i)
  {
    if (S[i] == 'W')
    {
      num_W[i] += num_W[i - 1] + 1;
      num_E[i] = num_E[i - 1];
    }
    else
    {
      num_E[i] += num_E[i - 1] + 1;
      num_W[i] = num_W[i - 1];
    }
  }

  int min_num = N;
  for (int i = 0; i < N; ++i)
  {
    int sum = num_W[i-1] + num_E[N - 1] - num_E[i];
    min_num = min(min_num, sum);
  }

  cout << min_num << endl;
}

void B_98()
{
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i < N-1; ++i)
  {
    string str1 = S.substr(0, i);
    string str2 = S.substr(i, N - i);
    int count = 0;

    for (int ch = 'a'; ch != 'z' + 1; ++ch)
    {
      int n1 = str1.find(ch);
      int n2 = str2.find(ch);
      if (n1 != string::npos && n2 != string::npos) ++count;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}

void A_98()
{
  int A, B;
  cin >> A >> B;

  long long max = A * (long long)B;
  if (max < A - B) max = A - B;
  if (max < A + B) max = A + B;

  cout << max << endl;
}

void C_99()
{
  int N;
  cin >> N;

  vector<int> dp(100010);
  dp[0] = 0;

  for (int i = 1; i <= 100000; ++i)
  {
    dp[i] = 100000;
    
    int p = 1;
    while (p <= i)
    {
      dp[i] = min(dp[i], dp[i - p] + 1);
      p *= 6;
    }

    int q = 1;
    while (q <= i)
    {
      dp[i] = min(dp[i], dp[i - q] + 1);
      q *= 9;
    }

    if (i == N) break;
  }

  cout << dp[N] << endl;
}

void B_99()
{
  int a, b;
  cin >> a >> b;

  int c = b - a;
  int sum = 0;
  for (int i = 1; i < c; ++i)
  {
    sum += i;
  }

  cout << sum-a << endl;
}

void A_99()
{
  int N;
  cin >> N;

  if (N < 1000)
  {
    cout << "ABC";
  }
  else
  {
    cout << "ABD";
  }
}