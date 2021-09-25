#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string str;
string buf;
vector<string> v[101];

int main()
{
	int n;
	cin >> n;
  getline(cin, str);
	for(int i = 0; i <= n; i++)
	{	
		getline(cin, str);
		stringstream ss(str);
		while (ss >> buf)
			v[i].push_back(buf);
	}
	getline(cin, str);
	istringstream ss(str);
	while (getline(ss, buf, ' '))
		v[n].push_back(buf);
	vector<string>::iterator prev;
	int size = v[n].size();
	for (int i = 0; i < n; i++)
	{
		prev = v[n].begin();
		for (int j = 0; j < v[i].size(); j++, size--)
		{
			if (find(v[n].begin(), v[n].end(), v[i][j]) == v[n].end() ||
				prev > find(v[n].begin(), v[n].end(), v[i][j]))
			{
				cout << "Impossible" << endl;
				return 0;
			}
			prev = find(v[n].begin(), v[n].end(), v[i][j]);
		}
	}
	if (size != 0)
		cout << "Impossible" << endl;
	else
		cout << "Possible" << endl;
	return 0;
}