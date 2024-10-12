#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  int res = 0;
  // 제료 수
  cin >> N;
  // 2개 합
  cin >> M;
  vector<int> L(N);
  for(int i = 0 ; i < N ; i++) {
    cin >> L[i];
  }

  sort(L.begin(), L.end());

  for(int i = 0 ; i < N ; i++) {
    for (int j = N - 1 ; j > i ; j--) {
      int sum = L[i] + L[j];
      if( sum > M)
        continue;
      else if ( sum == M) {
        res++;
        break;
      } else {
        break;
      }
    }
  }

  cout << res << endl;

}
