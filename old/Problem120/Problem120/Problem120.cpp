#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

void C_122()
{
  int N, M;
  cin >> N >> M;

  map<long long, int> A;
  vector<long long> B(N);
  for (int i = 0; i < N; ++i)
  {
    long long a;
    cin >> a >> B[i];
    if(A.count(a) == 0) A.insert(make_pair(a, i));
    else B[A[a]] += B[i];
  }

  long long sum = 0;
  for (auto itr = A.begin(); itr != A.end(); ++itr)
  {
    if (M < B[itr->second])
    {
      sum += itr->first * M;
      break;
    }
    else
    {
      sum += itr->first * B[itr->second];
      M -= B[itr->second];
    }
  }
  cout << sum << endl;
}

void C_122()
{
  int N, Q;
  string S;
  cin >> N >> Q >> S;

  vector<int> l(Q), r(Q);
  for (int i = 0; i < Q; ++i) cin >> l[i] >> r[i];

  int count = 0;
  vector<int> c((int)S.size());
  for (int i = 1; i < N; ++i)
  {
    if (S[i - 1] == 'A' && S[i] == 'C') ++count;
    c[i] = count;
  }

  for (int i = 0; i < Q; ++i)
  {
    cout << c[r[i] - 1] - c[l[i] - 1] << endl;
  }
}

long long gcd(long long a, long long b)
{
  if (a%b != 0)
  {
    return gcd(b, a%b);
  }
  else
  {
    return b;
  }
}

void C_128()
{
  int N;
  cin >> N;

  vector<long long> A(N+1);
  for (int i = 1; i < N+1; ++i) cin >> A[i];

  vector<long long> left(N+2), right(N+2);
  left[0]      = 0, left[1]  = A[1];
  right[N + 1] = 0, right[N] = A[N];
  for (int i = 2; i < N+1; ++i)
  {
    left[i] = gcd(A[i], left[i - 1]);
    right[(N + 1) - i] = gcd(A[(N + 1) - i], right[(N + 1) - i + 1]);
  }

  long long gcd_max = 0;
  for (int i = 1; i < N+1; ++i)
  {
    int a;
    if (left[i - 1] == 0)       a = right[i + 1];
    else if (right[i + 1] == 0) a = left[i - 1];
    else                        a = gcd(left[i - 1], right[i + 1]);

    if (gcd_max < a) gcd_max = a;
  }

  cout << gcd_max << endl;
}

void C_125()
{
  int N, M;
  cin >> N >> M;

  int L_max=0, R_min=N;
  for (int i = 0; i < M; ++i)
  {
    int L, R;
    cin >> L >> R;
    L_max = max(L_max, L);
    R_min = min(R_min, R);
  }
  int ans = R_min - L_max+1;
  ans = max(ans, 0);

  cout << ans << endl;
}


void C_1222()
{
  int N, M;
  cin >> N >> M;

  vector< vector<int> > light(M);
  for (int i = 0; i < M; ++i)
  {
    int k;
    cin >> k;
    light[i].resize(k);

    for (int j = 0; j < k; ++j)
    {
      cin >> light[i][j];
      --light[i][j];
    }
  }

  vector<int> p(M);
  for (int i = 0; i < M; ++i) cin >> p[i];

  int ans = 0;
  for (int i = 0; i < (1 << N); ++i)
  {
    bool ok = true;
    for (int j = 0; j < M; ++j)
    {
      
      int c = 0;
      for (int id : light[j])
      {
        if ((i >> id) & 1) ++c;
      }
      c %= 2;
      if (c != p[j]) ok = false;
    }

    if (ok == true) ++ans;
  }
  cout << ans << endl;
}


void C_129()
{
  int N, M;
  cin >> N >> M;

  vector<bool> broken_stairs(N+1, false);
  for (int i = 1; i < M+1; ++i)
  {
    int a;
    cin >> a;
    broken_stairs[a] = true;
  }

  vector<int> dp(N + 2);
  const long long mod = 1000000007;
  dp[N] = 1;
  for (int i = N - 1; i >= 0; --i)
  {
    if (broken_stairs[i])
    {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << endl;
}

void C_126()
{
  int N, K;
  cin >> N >> K;

  double probability = 0;
  for (int i = 1; i <= N; ++i)
  {
    int a = i;
    double temp = 1 / (double)N;

    while (a < K)
    {
      a *= 2;
      temp /= 2;
    }
    probability += temp;
  }
  cout << setprecision(10) << probability << endl;
}

void B_120()
{
  int A, B, K;
  cin >> A >> B >> K;

  int min = A < B ? A : B;
  int count = 0;
  for (int i = min; i > 0; --i)
  {
    if (B%i == 0 && A%i == 0) ++count;
    if (count == K)
    {
      cout << i << endl;
      return;
    }
  }
}

void A_120()
{
  int A, B, C;
  cin >> A >> B >> C;

  if (B / A > C) cout << C << endl;
  else cout << B / A << endl;
}

void B_121()
{
  int N, M, C;
  cin >> N >> M >> C;

  vector<int> B(M);
  for (int i = 0; i < M; ++i) cin >> B[i];

  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    int sum = 0;
    for (int j = 0; j < M; ++j)
    {
      int A;
      cin >> A;
      sum += A * B[j];
    }
    sum += C;
    if (sum > 0) ++count;
  }
  cout << count << endl;
}

void A_121()
{
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  cout << (H - h) * (W - w) << endl;
}

void B_122()
{
  string S;
  cin >> S;

  int max_length = 0;
  for (int i = 0; i < (int)S.size(); ++i)
  {
    if (S[i] != 'A' && S[i] != 'T' && S[i] != 'C' && S[i] != 'G') continue;

    int count = 1;
    for (int j = i + 1; j < (int)S.size(); ++j)
    {
      if (S[j] != 'A' && S[j] != 'T' && S[j] != 'C' && S[j] != 'G') break;
      ++count;
    }
    if (max_length < count) max_length = count;
  }
  cout << max_length << endl;
}

void A_122()
{
  char b;
  cin >> b;

  switch (b)
  {
  case 'A':
    cout << 'T' << endl;
    break;
  case 'T':
    cout << 'A' << endl;
    break;
  case 'C':
    cout << 'G' << endl;
    break;
  case 'G':
    cout << 'C' << endl;
    break;
  }
}

void B_123()
{
  vector<int> time(5);
  int diff_max = 0, sum = 0, max_index, add_value;
  for (int i = 0; i < 5; ++i)
  {
    cin >> time[i];

    int a = 10;
    while (a < time[i]) a += 10;

    if (diff_max <= a - time[i])
    {
      diff_max = a - time[i];
      max_index = i;
      add_value = a;
    }
    sum += a;
  }
  sum += time[max_index] - add_value;
  cout << sum << endl;
}

void A_123()
{
  vector<int> distance(5);
  int k;
  for (int i = 0; i < 5; ++i) cin >> distance[i];
  cin >> k;

  for (int i = 0; i < 5; ++i)
  {
    if (k < distance[i]-distance[0])
    {
      cout << ":(" << endl;
      return;
    }
  }
  cout << "Yay!" << endl;
}

void B_124()
{
  int N;
  cin >> N;

  int Mt_Max = 0;
  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    int H;
    cin >> H;

    if (Mt_Max <= H)++count;
    if (Mt_Max < H) Mt_Max = H;
  }
  cout << count << endl;
}

void A_124()
{
  int A, B;
  cin >> A >> B;

  int count = 0, sum = 0;
  while (count < 2)
  {
    if (A > B)
    {
      sum += A;
      --A;
    }
    else
    {
      sum += B;
      --B;
    }
    ++count;
  }
  cout << sum << endl;
}

void B_125()
{
  int N;
  cin >> N;

  vector<int> V(N), C(N);
  for (int i = 0; i < N; ++i) cin >> V[i];
  for (int i = 0; i < N; ++i) cin >> C[i];

  int sum = 0;
  for (int i = 0; i < N; ++i)
  {
    if (V[i] <= C[i]) continue;
    int diff = V[i] - C[i];
    sum += diff;
  }
  cout << sum << endl;
}

void A_125()
{
  int A, B, T;
  cin >> A >> B >> T;

  cout << T / A * B << endl;
}

void B_126()
{
  string S;
  cin >> S;

  int back_num = (S[2] - '0') * 10 + (S[3] - '0');
  int front_num = (S[0] - '0') * 10 + (S[1] - '0');

  bool isYYMM = false, isMMYY = false;
  if (0 < front_num && front_num < 13)
  {
    isMMYY = true;
    if (0 < back_num && back_num < 13)
    {
      isYYMM = true;
    }
  }
  if (0 < back_num && back_num < 13)
  {
    isYYMM = true;
  }

  if (isYYMM == true && isMMYY == true) cout << "AMBIGUOUS" << endl;
  else if (isYYMM == true && isMMYY == false) cout << "YYMM" << endl;
  else if (isYYMM == false && isMMYY == true) cout << "MMYY" << endl;
  else cout << "NA" << endl;
}

void A_126()
{
  int N, K;
  string S;
  cin >> N >> K >> S;

  for (int i = 0; i < N; ++i)
  {
    if (i + 1 == K) S[i] = S[i] + 32;
  }
  cout << S << endl;
}

void C_120()
{
  string S;
  cin >> S;

  int count_0 = 0, count_1 = 0;
  for (int i = 0; i < (int)S.length(); ++i)
  {
    if (S[i] - '0' == 0) ++count_0;
    else ++count_1;
  }

  if (count_0 > count_1) cout << count_1 * 2 << endl;
  else cout << count_0 * 2 << endl;
  return;
}

void C_123()
{
  long long N;
  cin >> N;

  long long max_numTimes = 0;
  for (int i = 0; i < 5; ++i)
  {
    long long capa;
    cin >> capa;

    long long times = N % capa == 0 ? N / capa : N / capa + 1;
    if (max_numTimes < times) max_numTimes = times;
  }

  cout << 5 + max_numTimes-1 << endl;
}

void C_124()
{
  string S;
  cin >> S;

  int count[2][2] = {};
  for (int i = 0; i < S.length(); ++i)
  {
    if (S[i] == '0') ++count[i % 2][0];
    else if (S[i] == '1') ++count[i % 2][1];
  }

  int a = count[0][0] + count[1][1];
  int b = count[0][1] + count[1][0];
  if (a < b) cout << a << endl;
  else cout << b << endl;

  return;
}