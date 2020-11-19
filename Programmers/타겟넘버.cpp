#include <string>
#include <vector>

using namespace std;

 int answer = 0;

    void dfs(vector<int> numbers, int target, int sum, int depth, int len) {
        if(depth == len) {
            if(target == sum) {
                answer++;
            }
            return;
        }
            dfs(numbers, target, sum + numbers[depth], depth + 1, len);
            dfs(numbers, target, sum - numbers[depth], depth + 1, len);
    }
int solution(vector<int> numbers, int target) {

    int len = numbers.size();
    dfs(numbers, target, 0, 0, len);
    return answer;
}