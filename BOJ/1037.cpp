#include <iostream>

using namespace std;

int n, temp;
int divisors[50];
long long Max;
bool flag;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> divisors[i];
        if (temp < divisors[i])
            temp = divisors[i];
    }
    Max = (long long)temp;
    while (1)
    {
        Max += (long long)temp;
        flag = true;
        for (int i = 0; i < n; i++)
        {
            if (Max % divisors[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << Max;
            break;
        }
    }
    return 0;
}