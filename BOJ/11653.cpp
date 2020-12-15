#include <iostream>

using namespace std;

int n ;

int main() {
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			n = n / i;
			cout << i << '\n';
			i--;
		}
	}	
	if (n > 1) cout << n;
	return 0;
}