#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int W, H, x, y;
  cin >> W >> H >> x >> y;
  double ans = (double)W*(double)H / (double)2;
  int num = (W == x * 2 && H == y * 2) ? 1 : 0;
  cout << setprecision(6) << ans << " " << num << endl;
}

void C_133()
{
  long long L, R;
  cin >> L >> R;

  set<int> s_i;
  int min_mod = 2019;
  for (long long i = L; i <= R; ++i)
  {
    if (s_i.size() == 2019) break;
    s_i.insert(i % 2019);

    set<int> s_j;
    for (long long j = i + 1; j <= R; ++j)
    {
      if (s_j.size() == 2019) break;
      s_j.insert(j % 2019);

      if (min_mod > (i*j) % 2019) min_mod = (i*j) % 2019;
      if (min_mod == 0) break;
    }
    if (min_mod == 0) break;
  }
  cout << min_mod << endl;
}

long long gcd(long long n, long long m)
{
  if (n%m == 0)
  {
    return m;
  }
  else
  {
    return gcd(m, n%m);
  }
}

long long lcm(long long n, long long m)
{
  return n * m / gcd(n, m);
}

void C_131()
{
  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  long long A_div, B_div;
  A_div = (A-1) / C + (A-1) / D - (A-1) / lcm(C, D);
  B_div = B / C + B / D - B / lcm(C, D);

  cout << (B - B_div) - ((A - 1) - A_div) << endl;
}

void C_132()
{
  int N;
  cin >> N;

  vector<int> d(N);
  for (int i = 0; i < N; ++i)  cin >> d[i];

  sort(d.begin(), d.end());

  cout << d[N / 2] - d[N / 2 - 1] << endl;
}

void C_134()
{
  int N;
  cin >> N;

  int higher[2] = { 0,0 };
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
    
    if (higher[0] < A[i])
    {
      higher[1] = higher[0];
      higher[0] = A[i];
    }
    else if (higher[1] < A[i]) higher[1] = A[i];
  }

  for (int i = 0; i < N; ++i)
  {
    if (higher[0] != A[i]) cout << higher[0] << endl;
    else cout << higher[1] << endl;
  }
}

void C_135()
{
  int N;
  cin >> N;

  vector<long long> A(N + 1);
  for (int i = 0; i < N + 1; ++i) cin >> A[i];

  long long rest = 0, down_mon = 0;
  for (int i = 0; i < N+1; ++i)
  {
    long long B;
    if (i != N) cin >> B;
    else        B = 0;

    if (A[i] <= rest)
    {
      down_mon += A[i];
      A[i] = 0;
    }
    else
    {
      down_mon += rest;
      A[i] -= rest;
    }

    if (A[i] <= B)
    {
      down_mon += A[i];
      rest = B - A[i];
    }
    else
    {
      down_mon += B;
      rest = 0;
    }
  }
  cout << down_mon << endl;
}

void C_136()
{
  int N;
  cin >> N;

  vector<long long> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  for (int i = 1; i < N; ++i)
  {
    if (h[i] > h[i - 1]) --h[i];
    else if (h[i] < h[i - 1])
    {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

void C_137()
{
  int N;
  cin >> N;

  map<string, int> already;
  for (int i = 0; i < N; ++i)
  {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    if (already.count(s) == 0)
    {
      already.insert(make_pair(s, 1));
    }
    else if (already.count(s) == 1)
    {
      ++already[s];
    }
  }

  long long count = 0;
  for (auto itr = already.begin(); itr != already.end(); ++itr)
  {
    long long n = itr->second;
    count += n * (n - 1) / 2;
  }
  cout << count << endl;
}

void C_138()
{
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; ++i) cin >> v[i];
  
  sort(v.begin(), v.end());

  float result = (v[0] + v[1]) / (float)2;
  for (int i = 2; i < N; ++i)
  {
    result = (result + v[i]) / (float)2;
  }

  cout << result << endl;
}

void C_139()
{
  int N;
  cin >> N;

  long long H_before;
  int count = 0, count_max = 0;
  for (int i = 0; i < N; ++i)
  {
    long long h;
    cin >> h;
   
    if (i == 0)
    {
      H_before = h;
      continue;
    }

    if (H_before >= h) ++count;
    else
    {
      if (count_max < count) count_max = count;
      count = 0;
    }
    H_before = h;
  }
  if (count_max < count) count_max = count;
  cout << count_max << endl;
}

void A_127()
{
  int A, B;
  cin >> A >> B;

  if (A < 13)
  {
    if (A < 6)
    {
      cout << 0 << endl;
      return;
    }
    cout << B / 2 << endl;
    return;
  }
  cout << B << endl;
}


void B_128()
{
  int N;
  cin >> N;

  vector< pair<pair<string, int>, int> > restaurant(N);
  for (int i = 0; i < N; ++i)
  {
    string s;
    int point;
    cin >> s >> point;
    restaurant[i] = make_pair(make_pair(s, -point), i + 1);
  }
  sort(restaurant.begin(), restaurant.end());

  for (int i = 0; i < N; ++i)
  {
    cout << restaurant[i].second << "\n";
  }
}

void A_128()
{
  int A, P;
  cin >> A >> P;

  cout << (A * 3 + P) / 2 << endl;
}

void B_129()
{
  int N;
  cin >> N;

  vector<int> W(N);
  int sum_W = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> W[i];
    sum_W += W[i];
  }

  int min_diff = sum_W, sum_Left = 0,sum_Right=0;
  for (int i = 0; i < N / 2; ++i)
  {
    sum_Left += W[i];
    sum_Right += W[N - 1 - i];

    if (min_diff > abs(sum_W - 2 * sum_Left))  min_diff = abs(sum_W - 2 * sum_Left);
    if (min_diff > abs(sum_W - 2 * sum_Right)) min_diff = abs(sum_W - 2 * sum_Right);
  }
  cout << min_diff << endl;
}

void A_129()
{
  int P, Q, R;
  cin >> P >> Q >> R;

  int min_flight = P+Q;
  if (min_flight > Q + R) min_flight = Q + R;
  if (min_flight > R + P) min_flight = R + P;

  cout << min_flight << endl;
}

void B_130()
{
  int N, X;
  cin >> N >> X;

  int count = 1, D = 0;
  for (int i = 0; i < N; ++i)
  {
    int L;
    cin >> L;
    D += L;

    if (D <= X)++count;
    else break;
  }
  cout << count << endl;
}

void A_130()
{
  int X, A;
  cin >> X >> A;

  if (X < A) cout << 0 << endl;
  else cout << 10 << endl;
}

void A_131()
{
  string S;
  cin >> S;

  for (int i = 0; i < (int)S.size()-1; ++i)
  {
    if (S[i] == S[i + 1])
    {
      cout << "Bad" << endl;
      return;
    }
  }
  cout << "Good" << endl;
}

void B_132()
{
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  int count = 0;
  for (int i = 0; i + 2 < n; ++i)
  {
    if (p[i] < p[i + 1])
    {
      if (p[i + 1] < p[i + 2]) ++count;
    }
    else
    {
      if (p[i + 1] > p[i + 2]) ++count;
    }
  }
  cout << count << endl;
}

void A_132()
{
  string S;
  cin >> S;

  map<char, int> mp;
  for (int i = 0; i < (int)S.size(); ++i)
  {
    if (mp.count(S[i]) == 0) mp.insert(make_pair(S[i], 1));
    else ++mp[S[i]];

    if (mp.size() > 2) break;
    if (mp[S[i]] > 2) break;

    if (i == (int)S.size() - 1)
    {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

void B_133()
{
  int N, D;
  cin >> N >> D;

  vector< vector<int> > x(N, vector<int>(D));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < D; ++j)
    {
      cin >> x[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = i+1; j < N; ++j)
    {
      
      int sum = 0;
      for (int k = 0; k < D; ++k)
      {
        int diff = x[i][k] - x[j][k];
        sum += diff * diff;
      }

      double root = sqrt(sum);
      if (floor(root) == root) ++count;
    }
  }
  cout << count << endl;
}

void A_133()
{
  int N, A, B;
  cin >> N >> A >> B;

  if (N*A > B) cout << B << endl;
  else cout << N * A << endl;
}

void B_134()
{
  int N, D;
  cin >> N >> D;

  if (N % (D * 2 + 1) == 0) cout << N / (D * 2 + 1) << endl;
  else cout << N / (D * 2 + 1) +1 << endl;
}

void A_134()
{
  int r;
  cin >> r;
  cout << 3 * r*r << endl;
}

void B_135()
{
  int N;
  cin >> N;

  int count = 0;
  for (int i = 1; i <= N; ++i)
  {
    int p;
    cin >> p;

    if (i != p) ++count;
    if (count > 2)
    {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}


void A_135()
{
  long long A, B;
  cin >> A >> B;

  if ((A + B) % 2 != 0) cout << "IMPOSSIBLE" << endl;
  else cout << (A + B) / 2 << endl;
}

void B_136()
{
  int N;
  cin >> N;

  int N_cpy = N;
  int digit = 0;
  while (N_cpy != 0)
  {
    N_cpy /= 10;
    ++digit;
  }


  int sum = 0;
  for (int i = 1; i < digit; i += 2)
  {
    sum += pow(10.0, i) - pow(10.0, i - 1);
  }
  if (digit % 2 != 0)  sum += N - (pow(10.0, digit - 1) - 1);

  cout << sum << endl;
}

void A_136()
{
  int A, B, C;
  cin >> A >> B >> C;

  if (C - (A - B) < 0) cout << 0 << endl;
  else cout << C - (A - B) << endl;
}

void B_137()
{
  int K, X;
  cin >> K >> X;

  for (int i = -(K - 1); i < K; ++i)
  {
    cout << X + i << " ";
  }
}

void A_137()
{
  int A, B;
  cin >> A >> B;

  int max=A+B;
  if (max < A - B) max = A - B;
  if (max < A*B) max = A * B;

  cout << max << endl;
}

void B_138()
{
  int N;
  cin >> N;

  long double sum = 0;
  for (int i = 0; i < N; ++i)
  {
    int A;
    cin >> A;
    sum += 1 / (long double)A;
  }
  cout << setprecision(14) << 1 / sum << endl;
}

void A_138()
{
  int a;
  string s;
  cin >> a >> s;

  if (a < 3200) cout << "red" << endl;
  else cout << s << endl;
}

void B_139()
{
  int A, B;
  cin >> A >> B;

  int num = 0;
  while(1)
  {
    if (B <= A * num - (num - 1))
    {
      cout << num << endl;
      return;
    }
    ++num;
  }
}

void A_139()
{
  string S, T;
  cin >> S >> T;

  int count = 0;
  for (int i = 0; i < (int)S.size(); ++i)
  {
    if (S[i] == T[i]) ++count;
  }
  cout << count << endl;
}
