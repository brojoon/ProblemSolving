#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, result;
int dp[100];

vector <vector <int> > v;

int Max(int a, int b) {
	return a > b ? a : b;
}

bool cmp(vector <int> a, vector <int> b) {
		return a[0] < b[0] ? true : false;
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) { 
		vector <int> tmp;
		cin >> a >> b;
		tmp.push_back(a);
		tmp.push_back(b);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);	
	
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(v[i][1] > v[j][1]) {
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
		result = Max(result, dp[i]);
	}
	cout << n - result;
	
	return 0;
}