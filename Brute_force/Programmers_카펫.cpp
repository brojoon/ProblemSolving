#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    
    for (int i = 1; i < sum / 2; i++)
    {
        if (sum % i == 0)
        {
            int a = sum / i;
            int b = i;
            
            if ((a - 2) * (b - 2) == yellow)
            {
                answer.push_back(a);
                answer.push_back(b);
                break;
            }
        }
    }
    return answer;
}