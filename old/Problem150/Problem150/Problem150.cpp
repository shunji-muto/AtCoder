#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <math.h>

using namespace std;

//void B_159()
int main()
{
  string S;
  cin >> S;

  int len = (int)S.size();
  string str1 = S.substr(0, (len - 1) / 2);
  string str2 = S.substr((len + 3)/2 - 1, (len - 1) / 2);
  
  bool b = true;
  string str1_r = str1;
  string str2_r = str2;
  string S_r = S;
  reverse(str1_r.begin(), str1_r.end());
  reverse(str2_r.begin(), str2_r.end());
  reverse(S_r.begin(), S_r.end());

  if (str1 != str1_r) b = false;
  if (str2 != str2_r) b = false;
  if (S != S_r)       b = false;

  if (b) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int CalcWay(int num, int sel)
{
  if (num == 1) return 0;

  int ans = 1;
  for (int i = 1; i <= sel; ++i)
  {
    ans = ans * (num - (i - 1)) / i;
  }
  return ans;
}

void A_159()
{
  int N, M;
  cin >> N >> M;

  int n1 = CalcWay(N, 2);
  int n2 = CalcWay(M, 2);

  cout << n1 + n2 << endl;
}

void C_158()
{
  int A, B;
  cin >> A >> B;

  for (int i = 0; i < 1010; ++i)
  {
    int x = i * 0.08;
    int y = i * 0.1;
    if (x == A && y == B)
    {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}

void B_158()
{
  long long N, A, B;
  cin >> N >> A >> B;

  long long div = N / (A + B);
  long long rest = N % (A + B);
  long long rest_bule = rest > A ? A : rest;

  cout << div * A + rest_bule << endl;
}

void A_158()
{
  string s;
  cin >> s;

  set<char> sets;
  for (int i = 0; i < 3; ++i)
  {
    sets.insert(s[i]);
  }

  if (sets.size() == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}


void C_157()
{
  int N, M;
  cin >> N >> M;

  bool b = true;
  vector<int> a(N, -1);
  for (int i = 0; i < M; ++i)
  {
    int s, c;
    cin >> s >> c;

    if (s == 1 && c == 0 && N != 1) b = false;

    if (a[s - 1] <= -1)
    {
      a[s - 1] = c;
    }
    else
    {
      if (a[s - 1] != c) b = false;
    }
  }


  if (M == 0)
  {
    if (N == 1) cout << 0;
    else cout << 1 * pow(10, N - 1);
    return;
  }

  if (b)
  {
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
      if (i == 0 && a[i] == -1)
      {
        sum += 1 * pow(10, N - (i + 1));
      }
      else if (a[i] == -1) sum += 0;
      else sum += a[i] * pow(10, N - (i + 1));
    }
    cout << sum;
  }
  else
  {
    cout << -1 << endl;
  }
}


void B_157()
{
  int A[3][3];
  bool hit[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
    {
      cin >> A[i][j];
      hit[i][j] = false;
    }

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    int b;
    cin >> b;

    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k)
      {
        if (A[j][k] == b) hit[j][k] = true;
      }
  }

  for (int i = 0; i < 3; ++i)
  {
    if      (hit[i][0] == true && hit[i][1] == true && hit[i][2] == true) break;
    else if (hit[0][i] == true && hit[1][i] == true && hit[2][i] == true) break;
    else if (hit[0][0] == true && hit[1][1] == true && hit[2][2] == true) break;
    else if (hit[0][2] == true && hit[1][1] == true && hit[2][0] == true) break;

    if (i == 2)
    {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

void A_157()
{
  int N;
  cin >> N;
  cout << ceil(N / (float)2) << endl;
}

void C_156()
{
  int N;
  cin >> N;

  vector<int> X(N);
  int sum_x = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> X[i];
    sum_x += X[i];
  }
  int ave_up   = ceil (sum_x / (float)N), ave_down = floor(sum_x / (float)N);
  int sum_up = 0, sum_down = 0;

  for (int i = 0; i < N; ++i)
  {
    sum_up   += (X[i] - ave_up)  *(X[i] - ave_up);
    sum_down += (X[i] - ave_down)*(X[i] - ave_down);
  }

  int min_sum = sum_up > sum_down ? sum_down : sum_up;

  cout << min_sum << endl;
}

void B_156()
{
  int N, K;
  cin >> N >> K;

  int count = 0;
  while (N > 0)
  {
    N /= K;
    ++count;
  }

  cout << count << endl;
}

void A_156()
{
  int N, R;
  cin >> N >> R;

  if (N < 10)
  {
    cout << R + 100 * (10 - N) << endl;
  }
  else
  {
    cout << R << endl;
  }
}

void C_155()
{
  int N;
  cin >> N;

  map<string, int> a;
  int max_num = 1;
  for (int i = 0; i < N; ++i)
  {
    string S;
    cin >> S;

    if (a.count(S) == 0)
    {
      a.insert(make_pair(S, 1));
    }
    else
    {
      ++a[S];
      if (a[S] > max_num) max_num = a[S];
    }
  }

  for (auto itr = a.begin(); itr != a.end(); ++itr)
  {
    if (itr->second == max_num) cout << itr->first << endl;
  }
}

void B_155()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    int A;
    cin >> A;

    if (A % 2 != 0) continue;
    if (A % 3 != 0 && A % 5 != 0)
    {
      cout << "DENIED" << endl;
      return;
    }
  }
  cout << "APPROVED" << endl;
}

void A_155()
{
  int A, B, C;
  cin >> A >> B >> C;

  set<int> num;
  num.insert(A);
  num.insert(B);
  num.insert(C);

  if (num.size() == 2) cout << "Yes" << endl;
  else cout << "No" << endl;

}

void C_154()
{
  int N;
  cin >> N;

  set<int> num;
  for (int i = 0; i < N; ++i)
  {
    int a;
    cin >> a;
    
    if (num.count(a) == 1)
    {
      cout << "NO" << endl;
      return;
    }
    else num.insert(a);
  }
  cout << "YES" << endl;
}

void B_154()
{
  string S;
  cin >> S;

  for (int i = 0; i < (int)S.size(); ++i) cout << "x";
}

void A_154()
{
  string S, T, U;
  int A, B;
  cin >> S >> T >> A >> B >> U;

  if (S == U) --A;
  else --B;

  cout << A << " " << B << endl;
}

void C_153()
{
  long long N, K;
  cin >> N >> K;

  if (K >= N)
  {
    cout << 0 << endl;
    return;
  }

  vector<long long> H(N);
  long long sum = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> H[i];
    sum += H[i];
  }
  sort(H.begin(), H.end());

  for (int i = 0; i < K; ++i)
  {
    sum -= H[N - 1 - i];
  }
  cout << sum << endl;
}

void B_153()
{
  int H, N;
  cin >> H >> N;


  for (int i = 0; i < N; ++i)
  {
    int A;
    cin >> A;
    H -= A;
  }
  if (H <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void A_153()
{
  int H, A;
  cin >> H >> A;

  cout << ceil(H / (double)A) << endl;
}

void C_152()
{
  int N;
  cin >> N;

  vector<int> P(N);
  int min_p = N, count = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> P[i];
  
    if (min_p >= P[i])
    {
      ++count;
      min_p = P[i];
    }

  }
  cout << count << endl;
}

void B_152()
{
  int a, b;
  cin >> a >> b;

  if (a < b)
  {
    for (int i = 0; i < b; ++i) cout << a;
  }
  else
  {
    for (int i = 0; i < a; ++i) cout << b;
  }
}

void A_152()
{
  int N, M;
  cin >> N >> M;

  if (N == M) cout << "Yes" << endl;
  else cout << "No" << endl;
}

void C_151()
{
  int N, M;
  cin >> N >> M;

  set<int> isAC;
  map<int, int>  WA_count;

  for (int i = 0; i < M; ++i)
  {
    int p;
    string S;
    cin >> p >> S;

    WA_count.insert(make_pair(p, 0));
    if (isAC.count(p) == 0)
    {
      if (S == "WA")
      {
        ++WA_count[p];
      }
      else
      {
        isAC.insert(p);
      }
    }
  }

  int sum = 0;
  for (auto itr = isAC.begin(); itr != isAC.end(); ++itr)
  {
    sum += WA_count[*itr];
  }
  cout << isAC.size() << " " << sum << endl;
}

void B_151()
{
  int N, K, M;
  cin >> N >> K >> M;

  int sum = 0;
  for (int i = 0; i < N - 1; ++i)
  {
    int A;
    cin >> A;
    sum += A;
  }

  int require_score = (M * N - sum) > 0 ? M * N - sum : 0;
  if (require_score <= K) cout << require_score << endl;
  else cout << -1 << endl;
}

void A_151()
{
  char C;
  cin >> C;

  cout << (char)(C + 1) << endl;
}

void C_150()
{
  int N;
  cin >> N;

  vector<int> P(N), Q(N), v(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  for (int i = 0; i < N; ++i)
  {
    cin >> Q[i];
    v[i] = i + 1;
  }

  int P_num = 0, Q_num = 0, number = 1;
  do
  {
    if (v == P) P_num = number;
    if (v == Q) Q_num = number;
    if (P_num != 0 && Q_num != 0) break;
    ++number;
  
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(P_num - Q_num) << endl;
}

void B_150()
{
  int N;
  string S;
  cin >> N >> S;
  
  int count = 0;
  for (int i = 0; i < N-2; ++i)
  {
    if (S.substr(i, 3) == "ABC") ++count;
  }

  cout << count << endl;
}

void A_150()
{
  int K, X;
  cin >> K >> X;

  if (X <= 500 * K)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
