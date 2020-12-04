#include <iostream>
#include <vector>
#define max 21
#define min(a, b) a < b ? a : b
#define abs(a) (a < 0 ? -a : a) 

using namespace std;

int n, start_i, start_j, link_i, link_j, start_sum, link_sum, result = 2147483647;

int map[max][max];


int main() {
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	for(int i = (1 << (n / 2 + 1)) - 1; i < (1 << n); i++) {
		vector<int> start, link;
		
		for(int j = 0; j < n; j++) {
		 	if(i & (1 << j)) start.push_back(j+1);
			else link.push_back(j + 1);
		}
		
		if (start.size() == link.size()) {
			start_sum = 0;
			link_sum = 0;
			for (int i = 0; i < n / 2; i++) {
				for(int j = i + 1; j < n / 2; j++) {
					start_i = start[i];
					start_j = start[j]; 
					
					start_sum += map[start_i][start_j] + map[start_j][start_i];
					
					link_i = link[i];
					link_j = link[j];
					
					link_sum += map[link_i][link_j] + map[link_j][link_i];
				}
			}
			result = min(result, abs((start_sum - link_sum)));
		}
	
	}
	cout << result;

	return 0;
}