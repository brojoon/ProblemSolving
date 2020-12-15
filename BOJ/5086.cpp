#include <iostream>

using namespace std;

int a, b;

int main() {
	
	while (1) {
		cin >> a >> b;
		if (!a && !b) {
			break;
		} 
		if (b / a > 0 && !(b % a))	cout << "factor" << '\n';
		else if(!(a % b)) cout << "multiple" << '\n'; 
		else cout << "neither" << '\n';
	}
	return 0;	
}