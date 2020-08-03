#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

//どこか間違っているらしい
void C_111()
{
  int n;
  cin >> n;


}

void C_112()
{
  int N;
  cin >> N;


}

void C_113()
{
  int N, M;
  cin >> N >> M;

  vector<int> P(M), Y(M);
  for (int i = 0; i < M; ++i) cin >> P[i] >> Y[i];


}

void B_113()
{
  int N, T, A;
  cin >> N >> T >> A;

  int idx;
  float abs_min = abs(A - 600);
  for (int i = 0; i < N; ++i)
  {
    int H;
    cin >> H;
    
    float temp = T - H * 0.006;
    if (abs_min > fabs(A - temp))
    {
      abs_min = abs(A - temp);
      idx = i + 1;
    }
  }

  cout << idx << endl;
}


void C_114()
{
  int N;
  cin >> N;

  int count = 0;
  vector<int> v = { 3,5,7 };
  do {
    int num = 0;;
    for (int i = v.size() - 1; i >= 0; --i) num += v[i] * pow(10.0, v.size() - 1 - i);
    if (N >= num) ++count;
  } while (next_permutation(v.begin(), v.end()));
  cout << count << endl;
}

void C_115()
{
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];
  sort(h.begin(), h.end());

  int min_diff = h[N - 1] - h[0];
  for (int i = 0; i+K-1< N; ++i)
  {
    min_diff = min(h[i + (K - 1)] - h[i], min_diff);
  }
  cout << min_diff << endl;
}

void C_116()
{
  int N;
  cin >> N;
  
  vector<int> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  int active = 0;
  int ans = 0;

  for (int i = 0; i < N; ++i)
  {
    if (active >= h[i])
    {
      active = h[i];
    }
    else
    {
      ans += h[i] - active;
      active = h[i];
    }
  }

  cout << ans << endl;
}

void C_117()
{
  int N, M;
  cin >> N >> M;

  if (N < M)
  {
    vector<int> X(M);
    for (int i = 0; i < M; ++i) cin >> X[i];
    sort(X.begin(), X.end());

    vector<int> diff(M - 1);
    for (int i = 0; i < M - 1; ++i) diff[i] = X[i + 1] - X[i];
    sort(diff.begin(), diff.end());

    int sum = 0;
    for (int i = 0; i < diff.size() - (N - 1); ++i)
    {
      sum += diff[i];
    }

    cout << sum << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}

void C_119()
{
  int N, A, B, C;
  cin >> N >> A >> B >> C;

  vector<int> l(N);
  int mp_min[3] = { 10000,10000,10000 };
  for (int i = 0; i < N; ++i)
  {
    cin >> l[i];
    int mp_temp[3] = { 0,0,0 };

    if (mp_min[0] > abs(A - l[i]))
    {

    }
    if (B)
    {

    }
    if (C)
    {

    }

  }
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

void C_118()
{
  int N;
  cin >> N;

  long long temp;
  for (int i = 0; i < N; ++i)
  {
    long long A;
    cin >> A;

    if (i == 0) temp = A;
    else temp = gcd(temp, A);
  }
  cout << temp << endl;
}

void B_110()
{
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int x_max = -101;
  for (int i = 0; i < N; ++i)
  {
    int x;
    cin >> x;
    if (x_max < x) x_max = x;
  }

  int y_min = 101;
  for (int i = 0; i < M; ++i)
  {
    int y;
    cin >> y;
    if (y_min > y) y_min = y;
  }

  if (x_max < y_min)
  {
    if (y_min > X && y_min <= Y)
    {
      cout << "No War" << endl;
      return;
    }
  }
  cout << "War" << endl;
}

void A_110()
{
  int A, B, C;
  cin >> A >> B >> C;

  int max = A;
  if (max < B) max = B;
  if (max < C) max = C;

  cout << A + B + C - max + max * 10 << endl;
}

void B_111()
{
  int N;
  cin >> N;

  for (int i = 1; i <= 9; ++i)
  {
    if (N <= i * 111)
    {
      cout << i * 111 << endl;
      return;
    }
  }
}

void A_111()
{
  string n;
  cin >> n;

  for (int i = 0; i < (int)n.size(); ++i)
  {
    if (n[i] == '1') n[i] = '9';
    else if (n[i] == '9') n[i] = '1';
  }
  cout << n << endl;
}

void B_112()
{
  int N, T;
  cin >> N >> T;

  int min_c = 10000,min_t=10000;
  for (int i = 0; i < N; ++i)
  {
    int c, t;
    cin >> c >> t;

    if (t <= T)
    {
      if (min_c > c)
      {
        min_t = t;
        min_c = c;
      }
    }
  }

  if (min_t <= 1000) cout << min_c << endl;
  else cout << "TLE" << endl;
}

void A_112()
{
  int a;
  cin >> a;

  if (a == 1)
  {
    cout << "Hello World" << endl;
  }
  else if (a == 2)
  {
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }
}

void A_113()
{
  int X, Y;
  cin >> X >> Y;

  cout << X + Y / 2 << endl;
}

void B_114()
{
  string S;
  cin >> S;

  int abs_min = 753 - 111;
  for (int i = 0; i < (int)S.size()-2; ++i)
  {
    int sum = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
    if (abs(753 - sum) < abs_min) abs_min = abs(753 - sum);
  }
  cout << abs_min << endl;
}

void A_114()
{
  int X;
  cin >> X;

  if (X == 3 || X == 5 || X == 7) cout << "YES" << endl;
  else cout << "NO" << endl;
}

void B_115()
{
  int N;
  cin >> N;

  int sum = 0, max = 0;
  for (int i = 0; i < N; ++i)
  {
    int p;
    cin >> p;

    if (max < p) max = p;
    sum += p;
  }

  cout << sum + max / 2 - max << endl;
}

void A_115()
{
  int D;
  cin >> D;

  switch (D)
  {
  case 22:
    cout << "Christmas Eve Eve Eve" << endl;
    break;
  case 23:
    cout << "Christmas Eve Eve" << endl;
    break;
  case 24:
    cout << "Christmas Eve" << endl;
    break;
  case 25:
    cout << "Christmas" << endl;
    break;
  }
}

void B_116()
{
  int s;
  cin >> s;

  set<int> key;
  key.insert(s);
  int count = 1;
  while (1)
  {
    if (s % 2 == 0)
    {
      s /= 2;
    }
    else
    {
      s = 3 * s + 1;
    }
    ++count;

    if (key.count(s) == 1) break;
    key.insert(s);
  }
  cout << count << endl;
}

void A_116()
{
  int AB, BC, CA;
  cin >> AB >> BC >> CA;

  cout << AB * BC / 2 << endl;
}

void B_117()
{
  int N;
  cin >> N;

  int max = 0, sum = 0;
  for (int i = 0; i < N; ++i)
  {
    int L;
    cin >> L;

    sum += L;
    if (max < L) max = L;
  }
  sum -= max;

  cout << sum << endl;

  if (max < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void A_117()
{
  int T, X;
  cin >> T >> X;

  cout << setprecision(10) << T / (double)X << endl;
}

void B_118()
{
  int N, M;
  cin >> N >> M;

  vector<int> A(M,0);
  for (int i = 0; i < N; ++i)
  {
    int K;
    cin >> K;

    for (int j = 0; j < K; ++j)
    {
      int a;
      cin >> a;
      ++A[a-1];
    }
  }

  int count = 0;
  for (int i = 0; i < M; ++i)
  {
    if (A[i] == N) ++count;
  }

  cout << count << endl;
}

void A_118()
{
  int A, B;
  cin >> A >> B;

  if (B%A == 0)
  {
    cout << A + B << endl;
  }
  else
  {
    cout << B - A << endl;
  }
}

void B_119()
{
  int N;
  cin >> N;

  double sum = 0;
  for (int i = 0; i < N; ++i)
  {
    double x;
    string u;
    cin >> x >> u;

    if (u == "JPY") sum += x;
    else sum += x * 380000;
  }
  cout << sum << endl;
}

void A_119()
{
  int y, m, d;
  char s1, s2;
  cin >> y >> s1 >> m >> s2 >> d;

  if (m > 4) cout << "TBD" << endl;
  else cout << "Heisei" << endl;
}

map<char, vector<int> > SerchChractorIndex(const string &s)
{
  map<char, vector<int> > chara_indexs;
  set<int> ignore_indexs;

  for (int i = 0; i < s.size(); ++i)
  {
    //探索済みの文字は調べない
    if (chara_indexs.count(s[i]) != 0) continue;

    vector<int> indexs;
    for (int j = 0; j < s.size(); ++j)
    {
      //すでに探索済みのindexは見ない
      if (ignore_indexs.count(j) != 0) continue;

      //インデックスリストに追加
      if (s[i] == s[j])
      {
        indexs.push_back(j);
        ignore_indexs.insert(j);
      }
    }

    //その文字のインデックスリストをmapに追加
    chara_indexs.insert(make_pair(s[i], indexs));
    delete &indexs;
  }
  ignore_indexs.clear();
  return chara_indexs;
}

void C_110()
{
  string S, T;
  cin >> S >> T;

  map<char, vector<int> > S_chraIndexs = SerchChractorIndex(S);
  map<char, vector<int> > T_chraIndexs = SerchChractorIndex(T);

  bool flag = false;
  for (map<char, vector<int> >::iterator itr_S = S_chraIndexs.begin(); itr_S != S_chraIndexs.end(); ++itr_S)
  {
    for (map<char, vector<int> >::iterator itr_T = T_chraIndexs.begin(); itr_T != T_chraIndexs.end(); ++itr_T)
    {
      if (itr_S->second == itr_T->second) 
      {
        flag = true;
        break;
      }
    }

    if(flag == false)
    {
      cout << "NO" << endl;
      return;
    }
    else flag = false;

  }
  cout << "YES" << endl;
  return ;
}