#include <iostream>

using namespace std;

int K, N, result;
int line[10001];
long long max = 0;
long long mid, min;

int main(void) {
    cin >> K >> N;

    for(int i = 0; i < K; i++) {
        cin >> line[i];
        if (max < line[i]) max = line[i];
    }

    min = 1;
    result = 0;

    while (min <= max) {
        mid = (min + max) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += line[i] / mid;
        }
        if (cnt >= N) {
            min = mid + 1;
            if (result < mid) result = mid;
        }
        else {
            max = mid - 1;
        }
    }
    cout << result;

    return 0;
}