#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

void A_TorT()
{
	int N, A, B;
	cin >> N >> A >> B;

	int total = (N * A < B) ? N * A : B;
  cout << total << endl;
}

void A_9x9() 
{
	int A, B;
	cin >> A >> B;

	if (A > 9 or B > 9) cout << "-1" << endl;
  else cout << A * B << endl;
}

void A_Circle()
{
	int r;
	cin >> r;
	
	cout << r*r;
}

void A_SerVsMon() 
{
	int H, A;
	cin >> H >> A;

	int attack_num = (H%A == 0) ? H / A : H / A + 1;
  cout << attack_num << endl;
}

void A_Poor() 
{
	int A, B, C;
	cin >> A >> B >> C;
	
	int counter = 0;
	if (A != B) counter = counter + 1;
	if (A != C) counter = counter + 1;
	if (counter == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
}

void B_Algae() 
{
	int r, D, x2000;
	cin >> r >> D >> x2000;
	
	int x = x2000;
	for (int i = 0; i < 10; ++i){
		x = r * x - D;
		cout << x << endl;
	}
}

void B_81() 
{
	int N;
	cin >> N;

	for (int i = 0; i < 9; ++i) {
		if (N % (9 - i) == 0) 
			if (N / (9 - i) < 10) {
				cout << "Yes" << endl;
				return;
			}
	}
	cout << "No" << endl;
}

void B_BiteEating() 
{
	int N, L;
	cin >> N >> L;
	
  int min = 100 + 200 - 1, sum = 0;
	for (int i = 0; i < N; ++i) {
		int taste = L + (i + 1) - 1;
		if (abs(min) > abs(taste)) min = taste;
		sum += taste;
	}
	cout << sum - min << endl;
}

int factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; ++i) {
		fac *= i;
	}
	return fac;
}

int CalcOrder(vector<int> v, int N) {
	int v_count = 1;
	for (int i = 0; i < N; ++i) {
		v_count += (v[i] - 1)*factorial(N - (i + 1));
		for (int j = i + 1; j < N; ++j) {
			if (v[i] < v[j]) --v[j];
		}
	}
	return v_count;
}

void C_CountOder(){
	int N; 
	cin >> N;

	vector<int> P(N);
	for (int i = 0; i < N; ++i) cin >> P[i];
	vector<int> Q(N);
	for (int i = 0; i < N; ++i) cin >> Q[i];
	
	int P_count = CalcOrder(P, N);
	int Q_count = CalcOrder(Q, N);
	
  cout << abs(P_count - Q_count) << endl;
}

void C_WelcomeAtcoder() {
  int N, M;
  cin >> N >> M;

  ++N;
  int AC_num = 0, WA_num = 0;
  vector<bool> AC(N, false);
  vector<int>  WA(N, 0);
  for (int i = 0; i < M; ++i) 
  {
    int p;
    string S;
    cin >> p >> S;

    if (AC[p] == false && S == "AC")
    {
      ++AC_num;
      WA_num += WA[p];
      AC[p] = true;
    }
    else if (AC[p] == false && S == "WA") ++WA[p];
  }
  cout << AC_num << " " << WA_num << endl;
}

void C_LowElements() {
	int N;
	cin >> N;

  int min = N, count = 0;
  for (int i = 0; i < N; ++i)
  {
    int P;
    cin >> P;

    if (min >= P)
    {
      ++count;
      min = P;
    }
  }
	cout << count << endl;
}

void C_FenVsMon() 
{
	int N, M;
	cin >> N >> M;

	vector<int> H(N);
	for (int i = 0; i < N; ++i) cin >> H[i];

	long long sum = 0;
	sort(H.begin(), H.end());
	for (int i = 0; i < N-M; ++i) sum += H[i];
	cout << sum << endl;
}

void C_DisOrNot()
{
  int N;
  cin >> N;

  set<int> A;
  for (int i = 0; i < N; ++i)
  {
    int a;
    cin >> a;

    auto r = A.insert(a);
    if (r.second == false)
    {
      cout << "NO" << endl;
      break;
    }
    if (N == i + 1) cout << "YES" << endl;
  }
}


int main()
{
	//A_TorT();
	//A_9x9();
	//A_Circle();
	//A_SerVsMon();
	//B_Algae();
	//B_81();
	//B_BiteEating();
	//C_CountOder();
	//C_WelcomeAtcoder();
	//C_LowElements();
	//C_FenVsMon();
	C_DisOrNot();
}

