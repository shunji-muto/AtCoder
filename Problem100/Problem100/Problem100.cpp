//100,103,109完了

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

void C_108()
{


}

void B_100()
{
  int D, N;
  cin >> D >> N;

  if (D == 0)
  {
    int i = 0, count = 0;
    while (1)
    {
      ++i;
      if (i % 100 == 0) continue;
      
      ++count;
      if (count == N)
      {
        cout << i << endl;
        break;
      }
    }
  }
  else
  {
    long long a = pow(100.0, D);
    cout << a * N << endl;
  }
}

void A_100()
{
  int A, B;
  cin >> A >> B;

  bool b = true;
  if (A > 8 || B > 8) b = false;

  if (b == true) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}

void B_101()
{
  long long N;
  cin >> N;
  string str = to_string(N);

  int sum = 0;
  for (int i = 0; i < (int)str.size(); ++i)
  {
    sum += (str[i] - '0');
  }

  if (N%sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void A_101()
{
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < (int)S.size(); ++i)
  {
    if (S[i] == '+') ++count;
    else --count;
  }
  cout << count << endl;
}

void B_102()
{
  int N;
  cin >> N;

  long long a_max = 0, a_min = 10000000000;
  for (int i = 0; i < N; ++i)
  {
    long long A;
    cin >> A;
    if (a_max < A)a_max = A;
    if (a_min > A) a_min = A;
  }

  cout << a_max - a_min << endl;
}

void A_102()
{
  long long N;
  cin >> N;

  if (N % 2 == 0) cout << N << endl;
  else cout << N * 2 << endl;
}

void B_103()
{
  string S, T;
  cin >> S >> T;

  for (int i = 0; i < (int)S.size(); ++i)
  {
    char chara_keeper = S[0];
    for (int j = 0; j < (int)S.size(); ++j)
    {
      char s = S[(j + 1) % (int)S.size()];
      S[(j + 1) % (int)S.size()] = chara_keeper;
      chara_keeper = s;
    }

    if (S == T)
    {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

void A_103()
{
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  sort(a.begin(), a.end());

  cout << abs(a[1] - a[0]) + abs(a[2] - a[1]) << endl;
}

//問題文がクソ
void B_104()
{
  string S;
  cin >> S;

  if (S[0] == 'A')
  {
    for (int i = 2; i < (int)S.size() - 1; ++i)
    {
      if (S[i] == 'C')
      {
        cout << "AC" << endl;
        return;
      }
    }
  }
  cout << "WA" << endl;
}

void A_104()
{
  int R;
  cin >> R;

  if (R < 1200) cout << "ABC" << endl;
  else if (1200 <= R && R < 2800) cout << "ARC" << endl;
  else cout << "AGC" << endl;
}

void B_105()
{
  int N;
  cin >> N;

  for (int i = 0; i < 100 / 4 + 1; ++i)
  {
    for (int j = 0; j < 100 / 7 + 1; ++j)
    {
      if (N == i * 4 + j * 7)
      {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

void A_105()
{
  int N, K;
  cin >> N >> K;

  if (N%K == 0) cout << 0 << endl;
  else cout << 1 << endl;
}

void B_106()
{
  int N;
  cin >> N;

  int count = 0;
  for (int i = 105; i <= N; i+=2)
  {
    int div_num = 0;
    for (int j = 1; j*j <= i; ++j)
    {
      if (j*j == i)
      {
        ++div_num;
        continue;
      }
      if (i%j == 0) div_num += 2;
    }
    if (div_num == 8) ++count;
  }
  cout << count << endl;
}

void A_106()
{
  int A, B;
  cin >> A >> B;

  cout << (A - 1)*(B - 1) << endl;
}

void B_107()
{
  int H, W;
  cin >> H >> W;

  vector<bool> col(H,false), row(W,false);
  vector< vector<char> > squares(H, vector<char>(W));
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> squares[i][j];
      if (i == 0)
      {
        if (squares[i][j] == '.') row[j] = true;
      }
      else
      {
        if (squares[i][j] == '#') row[j] = false;
      }

      if (j == 0)
      {
        if (squares[i][j] == '.') col[i] = true;
      }
      else
      {
        if (squares[i][j] == '#') col[i] = false;
      }
    }
  }

  for (int i = 0; i < H; ++i)
  {
    if (col[i] == true) continue;
    for (int j = 0; j < W; ++j)
    {
      if (row[j] == true) continue;
      cout << squares[i][j];
    }
    cout << endl;
  }
}

void A_107()
{
  int N, i;
  cin >> N >> i;

  cout << N - i + 1 << endl;
}

void B_108()
{
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int diff_x = x2 - x1, diff_y = y2 - y1;
  cout << x2 - diff_y << " " << y2 + diff_x << " " << x1 - diff_y << " " << y1 + diff_x;
}

void A_108()
{
  int K;
  cin >> K;

  int even = K / 2;
  int odd = K - K / 2;

  cout << even * odd << endl;
}

void B_109()
{
  int N;
  cin >> N;

  set<string> word;
  bool rule = true;
  char last_chara = '0';
  for (int i = 0; i < N; ++i)
  {
    string w;
    cin >> w;

    if (word.count(w) == 1) rule = false;
    else word.insert(w);

    if (i == 0)
    {
      last_chara = w[w.size() - 1];
      continue;
    }
    
    if (last_chara != w[0]) rule = false;
    last_chara = w[w.size() - 1];
  }

  if (rule == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void A_109()
{
  int A, B;
  cin >> A >> B;

  if (A % 2 == 1 && B % 2 == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void C_100() 
{
  int N;
  cin >> N;

  int div_num = 0;
  for (int i = 0; i < N; ++i)
  {
    int a;
    cin >> a;

    //奇数になるまで割り続ける
    while (a % 2 == 0)
    {
      a = a / 2;
      ++div_num;
    }
  }
  cout << div_num << endl;
}

//わからんとばす
void C_101() 
{
  int N, K;
  cin >> N >> K;

  int element_min = N, min_index = 0;
  vector<int> A(N,0);
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
    if (element_min > A[i])
    {
      element_min = A[i];
      min_index = i;
    }


  }
}

//わからない
void C_102()
{
  int N;
  cin >> N;

  int A_sum = 0, A_absSum = 0;
  for (int i = 0; i < N; ++i)
  {
    int A;
    cin >> A;
    A_sum += A - (i + 1);
    A_absSum += abs(A - (i + 1));
  }

  double sum_div = round((double)A_sum / N);
  if (sum_div == 0) cout << A_absSum << endl;
  else
  {
    A_sum += -sum_div * N;
    cout << abs(A_sum) << endl;
  }
}

void C_103()
{
  int N;
  cin >> N;

  int a_sum=0;
  for (int i = 0; i < N; ++i)
  {
    int a;
    cin >> a;
    a_sum += a - 1;
  } 

  cout << a_sum << endl;
}

//わからない
void C_104()
{
  cout << "a";
}

//わからん
void C_105()
{
  int N;
  cin >> N;
}

int ctoi(char c)
{
  if (c >= '0' && c <= '9') return c - '0';
  return 0;
}

long Exponentiation(long k, int n)
{
  long count = 0;
  while (k>1)
  {
    k = k / n;
    ++count;
  }
  return count;
}

//わからない
void C_106()
{
  string S;
  long K;
  cin >> S >> K;

  //1兆＝1000000000000(10^12)
  long long num=0;
  for (int i = 0; i < S.size(); ++i)
  {
    int n = ctoi(S[i]);
    num += Exponentiation(K, n);

    if (num >= K)
    {
      cout << n << endl;
      return;
    }
    else K - num;
  }
}

//わからん
void C_107()
{
  int N, K;
  cin >> N >> K;

  set<int> x_tree;
  x_tree.insert(0);
  int max_x = 0;
  for (int i = 0; i < N; ++i)
  {
    int x;
    cin >> x;
    x_tree.insert(x);
    if (max_x < x) max_x = x;
  }


  int candle_num = 0, dis_sum = 0;
  double min_cost = max_x;

  auto itr_0 = x_tree.find(0);
  for (auto itr = itr_0; itr != x_tree.end(); ++itr)
  {
    ++candle_num;
    dis_sum += *itr;
    double cost = dis_sum / candle_num;
    if (min_cost > cost) min_cost = cost;
  }
}

//約数列挙
vector<int> Divisor(int n)
{
  vector<int> ret;
  for (int i = 1; i*i <= n; ++i)
  {
    if (n%i == 0)
    {
      ret.push_back(i);
      if (i*i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

void C_109()
{
  int N, X;
  cin >> N >> X;

  vector<int> city_dis(N);
  for (int i = 0; i < N; ++i)
  {
    int city;
    cin >> city;
    city_dis[i] = abs(city - X);
  }

  //座標の差の最小値の約数を求める
  int min_dis = *min_element(city_dis.begin(), city_dis.end());
  vector<int> divisors = Divisor(min_dis);

  for (int i = divisors.size() - 1; i >= 0; --i)
  {
    //min_disの約数が他の約数となるか？
    for (int j = 0; j < N; ++j)
    {
      if (city_dis[j] % divisors[i] != 0) break;
      if (j == N - 1)
      {
        cout << divisors[i] << endl;
        return;
      }
    }
  }
  cout << "1" << endl;
}

int main()
{
  //C_100();
  //C_103();
  //C_109();
  //B_107();
  //A_105();
  //B_103();
}