#include <iostream>
#include <string>
#include <stack>

using namespace std;

int count;
stack<char> myStack;
string str;

void Solution()
{
	cin >> str;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] == '(')
			myStack.push('(');
		else
		{
			myStack.pop();
			if (str[i - 1] == '(')
				count += myStack.size();
			else if (str[i - 1] == ')')
				count++;
		}
	}
	cout << count << endl;
}

int main()
{
	Solution();
}