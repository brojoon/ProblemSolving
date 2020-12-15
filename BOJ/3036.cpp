#include <iostream>

using namespace std;

int n, d;

int rings[100];

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b; 
}

int main() {
	cin >> n;
	cin >> rings[0];
	for(int i = 1; i < n; i++) {
		cin >> rings[i];
		d = gcd(rings[0], rings[i]);
		cout << rings[0] / d << "/" << rings[i] / d << '\n';
	}
	return 0;
}