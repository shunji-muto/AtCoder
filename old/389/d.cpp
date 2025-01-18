#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main()
{
    long long R;
	cin >> R;

    long long base_block = 1+(R-1)*2;
    long long total_block = (R*(1+base_block)) - base_block;

    cout << total_block << endl;
}
