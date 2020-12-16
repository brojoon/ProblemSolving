#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bags;
vector<pair<int, int> > jewels;
int n, k, first, second, j;
long long sum;
priority_queue<int> pq;


int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> first >> second; 
        jewels.push_back(make_pair(first, second));
    }
    for(int i = 0; i < k; i++) {
        cin >> first;
        bags.push_back(first);
    }
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    for(int i = 0, j = 0; i < k; i++) {
        while(j < n && jewels[j].first <= bags[i])
            pq.push(jewels[j++].second);
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}