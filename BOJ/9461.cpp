#include <iostream>

using namespace std;

int t, n;
long long fibo[101];

int main() {
	cin >> t;
	fibo[1] = 1;
	fibo[2] = 1;
	
	for (int j = 3; j <= 100; j++) {
		fibo[j] = fibo[j - 2] + fibo[j - 3];
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fibo[n] << '\n';
	}
}