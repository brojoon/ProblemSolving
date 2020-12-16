#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t, n, result, flag;

string s;

vector<pair<string, int>> v;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        v.clear();
        result = 1;
        for (int i = 0; i < n; i++)
        {
            flag = 0;
            cin >> s >> s;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].first == s)
                {
                    v[i].second++;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                v.push_back(make_pair(s, 1));
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            result *= v[i].second + 1;
        }
        cout << result - 1 << '\n';
    }
}