#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
  A_160();
}