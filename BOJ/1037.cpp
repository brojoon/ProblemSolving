#include <iostream>
#include <algorithm>

using namespace std;

int n;
int divisors[50];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> divisors[i];
    sort(divisors, divisors + n);
    cout << divisors[0] * divisors[n - 1]; 
	
	return 0;
}