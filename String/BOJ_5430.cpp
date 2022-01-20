#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <deque>


using namespace std;

int T;
int N;
size_t cur;
bool R;
bool flag;
deque<string> dq;

string s;
string arr2;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) dq.push_back(tmp);
 
    return result;
}


void Solution() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		flag = false;
		cin >> s;
		cin >> N;
		cin >> arr2;
		arr2.erase(0, 1);
		arr2.erase(arr2.length() - 1, 1);
		vector <string> arr = split(arr2, ',');
		if (arr.size() == 0) {
			cout << "error" << endl;
			continue;
		}
		cur = 0;
		for (int i = 0; i < s.length(); i++) {
			if (arr.size() == 0) {
				cout << "error" << endl;
				flag = true;
				break;
			}
			if (s[i] == 'R') {
				R = !R;
				if (R) cur = arr.size() - 1;
				else cur = 0;

			}
			else {
				arr.erase(arr.begin() + cur);
				if (arr.size() == 0) continue;
				if (R) cur = arr.size() - 1;
				else cur = 0;
			}
		}
		if (!flag) {
			if (!R) {
				cout << '[';
				for (int i = 0; i < arr.size(); i++) {
					cout << arr[i];
					if (i != arr.size() - 1) cout << ',';
				}
				cout << ']';
			} else {
				cout << '[';
				for (int i = arr.size() - 1; i >= 0; i--) {
					cout << arr[i];
					if (i != 0) cout << ',';
				}
				cout << ']';
			}
			cout << endl;
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}