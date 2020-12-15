#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, element, tmp;
string s;
queue<int> q;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> element;
            q.push(element);
        }
        else if (s == "front")
        {
            if (q.size() == 0)
                tmp = -1;
            else
                tmp = q.front();
            cout << tmp << '\n';
        }
        else if (s == "back")
        {
            if (q.size() == 0)
                tmp = -1;
            else
                tmp = q.back();
            cout << tmp << '\n';
        }
        else if (s == "empty")
        {
            if (q.empty())
                tmp = 1;
            else
                tmp = 0;
            cout << tmp << '\n';
        }
        else if (s == "size")
        {
            if (q.size())
                tmp = q.size();
            else
                tmp = 0;
            cout << tmp << '\n';
        }
        else if (s == "pop")
        {
            if (q.size())
            {
                tmp = q.front();
                q.pop();
            }
            else
                tmp = -1;
            cout << tmp << '\n';
        }
    }
    return 0;
}