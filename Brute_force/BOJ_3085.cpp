#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 50

int N;

string board[MAX];

int findMaxCandy() {
    int result = 1;

    for (int i = 0; i < N; i++) {
        int tmp = 1;
        for(int j = 1; j < N; j++) {
            if (board[i][j - 1] == board[i][j])
                tmp++;
            else {
                result = max(result, tmp);
                tmp = 1;
            }
        }
        result = max(result, tmp);
    }

    for(int i = 0; i < N; i++) {
        int tmp = 1;
        for (int j = 0; j < N - 1; j++) {
            if (board[j + 1][i] == board[j][i])
                tmp++;
            else {
                result = max(result, tmp);
                tmp = 1;
            }
        }
        result = max(result, tmp);
    }
    return result;
}


int main(void) {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            swap(board[i][j], board[i][j + 1]);
            result = max(result, findMaxCandy());
            swap(board[i][j], board[i][j + 1]);

            swap(board[j][i], board[j + 1][i]);
            result = max(result, findMaxCandy());
            swap(board[j][i], board[j + 1][i]);

        }
    }

    cout << result << '\n';
    return 0;
}