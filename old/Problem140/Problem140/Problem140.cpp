#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <iomanip>


#define rep(i,n) for(int i=0; i< (n); ++i)

using namespace std;

int main()
{
  int N;
  cin >> N;

  int sum = 0;
  vector<int> A(N), C(N - 1);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < N; ++i)
  {
    int B;
    cin >> B;
    sum += B;
  }
  for (int i = 0; i < N - 1; ++i) cin >> C[i];

  for (int i = 0; i < N - 1; ++i)
  {
    if (A[i + 1] == A[i] + 1)
    {
      sum += C[A[i]-1];
    }
  }

  cout << sum << endl;
}

void C_140()
{
  int N;
  cin >> N;

  vector<int> B(N-1);
  rep(i, N - 1) cin >> B[i];

  vector<int> A(N);
  for (int i = 1; i < N - 1; ++i) A[i] = min(B[i - 1], B[i]);
  int sum=0;
  for (int i = 1; i < N - 1; ++i) sum += A[i];
  cout << sum+B[0]+B[N-2] << endl;
  return;
}

void C_141()
{
  int N, K, Q;
  cin >> N >> K >> Q;

  vector<int> point(N, 0);
  for (int i = 0; i < Q; ++i)
  {
    int A;
    cin >> A;
    ++point[A - 1];
  }

  for (int i = 0; i < N; ++i)
  {
    if (0 >= K - (Q - point[i])) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}

void C_142()
{
  int N;
  cin >> N;

  vector<int> student(N);
  for (int i = 0; i < N; ++i)
  {
    int A;
    cin >> A;
    student[A - 1] = i+1;
  }

  for (int i = 0; i < N; ++i) cout << student[i] << endl;
}



void C_143()
{
  int N;
  string S;
  cin >> N >> S;

  int slime_num = 1;
  for (int i = 1; i < (int)S.size(); ++i)
  {
    if (S[i] != S[i - 1]) ++slime_num;
  }
  cout << slime_num << endl;
}

void C_144()
{
  long long N;
  cin >> N;

  long long div = sqrt(N);

  for (int i = div; i > 0; --i)
  {
    if (N%i == 0)
    {
      div = i;
      break;
    }
  }
  cout << div + N / div - 2 << endl;
}

struct Vec2d
{
  double x;
  double y;
};


void C_145()
{
  int N;
  cin >> N;

  vector<Vec2d> pos(N);
  vector<int> v(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> pos[i].x >> pos[i].y;
    v[i] = i;
  }

  double sum_distance = 0.0;
  int count = 0;
  do{
    ++count;
    for (int i = 0; i < v.size() - 1; ++i)
    {
      double dis = pow(pos[v[i]].x - pos[v[i + 1]].x, 2) + pow(pos[v[i]].y - pos[v[i + 1]].y, 2);
      sum_distance += sqrt(dis);
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << setprecision(10) << sum_distance / count << endl;
}

int CountDigit(long long a)
{
  int digit = 0;
  while (a != 0)
  {
    a /= 10;
    ++digit;
  }
  return digit;
}

void C_146()
{
  long long A, B, X;
  cin >> A >> B >> X;

  if (X > A * 1000000000 + B * 10)
  {
    cout << 1000000000 << endl;
    return;
  }

  long long buy_max = 1000000000, buy_min = 0;
  while (1)
  {
    long long mid = (buy_max + buy_min) / 2;
    int digit = CountDigit(mid);

    if (X > A * mid + B * digit) buy_min = mid;
    else buy_max = mid;
    if (buy_min + 1 == buy_max) break;
  }

  if (X >= A * buy_max + B * CountDigit(buy_max)) cout << buy_max << endl;
  else cout << buy_min << endl;
}

int gcd(int n, int m)
{
  if (n%m == 0) return m;
  else return (gcd(m, n%m));
}

long long lcm(int n, int m)
{
  return ((long long)n * m / gcd(n, m));
}

void C_148()
{
  int A, B;
  cin >> A >> B;

  if (A < B)
  {
    int C = B;
    B = A;
    A = C;
  }

  cout << lcm(A, B) << endl;
}

void C_149()
{
  int X;
  cin >> X;

  while (1)
  {
    int count = 0;
    for (int i = 1; i*i <= X; ++i)
    {
      if (X%i == 0)
      {
        if (i*i != X) count += 2;
        else ++count;
      }
    }

    if (count == 2)
    {
      cout << X << endl;
      return;
    }
    ++X;
  }
}

void A_149()
{
  string S, T;
  cin >> S >> T;

  cout << T << S << endl;
}

void B_149()
{
  long long A, B, K;
  cin >> A >> B >> K;

  A -= K;
  if (A < 0)
  {
    B += A;
    A = 0;
  }
  if (B < 0) B = 0;

  cout << A << " " << B << endl;
}

void A_148()
{
  int A, B;
  cin >> A >> B;

  for (int i = 1; i < 4; ++i)
  {
    if (i != A && i != B) cout << i << endl;
  }
}

void B_148()
{
  int N;
  string S, T;
  cin >> N >> S >> T;

  for (int i = 0; i < N; ++i)
  {
    cout << S[i] << T[i];
  }
}

void A_147()
{
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  if (A1 + A2 + A3 > 21) cout << "bust" << endl;
  else cout << "win" << endl;
}

void B_147()
{
  string S;
  cin >> S;

  int S_size = (int)S.size();
  int count = 0;
  for (int i = 0; i < S_size / 2; ++i)
  {
    if (S[i] != S[S_size - 1 - i]) ++count;
  }
  cout << count << endl;
}

void A_146()
{
  string S;
  cin >> S;

  vector<string> week{ "SUN","MON","TUE","WED","THU","FRI","SAT" };

  for (int i = 0; i < week.size(); ++i)
  {
    if (week[i] == S)
    {
      cout << 7 - i << endl;
      return;
    }
  }
  
}

void B_146()
{
  int N;
  string S;
  cin >> N >> S;

  for (int i = 0; i < (int)S.size(); ++i)
  {
    if (S[i] + N > 'Z') S[i] = 'A' + (S[i] + N - 'Z' - 1);
    else S[i] = S[i] + N;
  }
  cout << S << endl;
}

void B_145() 
{
  int N;
  string S;
  cin >> N >> S;

  if (N % 2 != 0)
  {
    cout << "No" << endl;
    return;
  }
  else
  {
    for (int i = 0; i < N / 2; ++i)
    {
      if (S[i] != S[N / 2 + i])
      {
        cout << "No" << endl;
        return;
      }
    }
    cout << "Yes" << endl;
  }
}

void A_143()
{
  int A, B;
  cin >> A >> B;

  if (A - B * 2 < 0) cout << 0 << endl;
  else cout << A - B * 2 << endl;
}

void B_143()
{
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; ++i) cin >> d[i];

  int sum = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = i+1; j < N; ++j)
    {
      sum += d[i] * d[j];
    }
  }
  cout << sum << endl;
}

void A_142()
{
  int N;
  cin >> N;

  cout << std::setprecision(10) << (N - (N / 2)) / (double)N << endl;
}

void B_142()
{
  int N, K;
  cin >> N >> K;

  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    int h;
    cin >> h;
    if (K <= h) ++count;
  }
  cout << count << endl;
}

void A_141()
{
  string S;
  cin >> S;

  if (S == "Sunny") cout << "Cloudy" << endl;
  else if (S == "Cloudy") cout << "Rainy" << endl;
  else if (S == "Rainy") cout << "Sunny" << endl;
}

void B_141()
{
  string S;
  cin >> S;

  for (int i = 0; i < (int)S.size(); ++i)
  {
    //奇数
    if (i % 2 == 0 && S[i] == 'L')
    {
      cout << "No" << endl;
      return;
    }
    //偶数
    else if (i % 2 != 0 && S[i] == 'R')
    {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

void A_140()
{
  int N;
  cin >> N;

  cout << N * N*N << endl;
}

//問題の意味が常人には理解不能，学生やり直せ
void B_140()
{
  int N;
  cin >> N;


}