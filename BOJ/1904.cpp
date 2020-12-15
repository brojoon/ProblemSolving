#include <iostream>

using namespace std;

int n;
long long fibo[1000000];

int main() {
	cin >> n;
	fibo[0] = 1;
	fibo[1] = 2;
	for(int i = 2; i <= n; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 15746;
	}
	
	cout << fibo[n - 1];
	
	return 0;
}