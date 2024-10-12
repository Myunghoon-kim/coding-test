#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
  int T, K;

  cin >> T;

  int res[T];

  for(int i = 0 ; i < T ; i++) {
    cin >> K;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    // 입력 받기
    for(int j = 0 ; j < K ; j++) {
      int tmp;
      cin >> tmp;
      pq.push(tmp);
    }
    while(!pq.empty()) {
      cout << "pq size " << pq.size() << endl;
      if( pq.size() == 1) {
        sum = sum + pq.top();
        pq.pop();
        continue;
      }
      //first
      int f1 = pq.top();
      pq.pop();
      int f2 = pq.top();
      pq.pop();

      sum = f1 + f2;
      pq.push(sum);
    }
    cout << sum << endl;
  }

}
