#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M,N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  vector<int> datas(N, 0);

  for (int i = 0; i < N ; i++) {
    cin >> datas[i];
  }
  sort(datas.begin(), datas.end());

  cin >> M;
  vector<bool> find(M, false);
  for (int i = 0; i < M ; i++) {
    bool founded = false;
    int target;
    cin >> target;
    int start_index = 0;
    int end_index = datas.size() - 1;

    while( start_index <= end_index) {
      int mid_index = (start_index + end_index) / 2;
      int mid_value = datas[mid_index];

      if( mid_value > target)
        end_index = mid_index -1;
      else if (mid_value < target)
        start_index = mid_index+1;
      else {
        founded = true;
        break;
      }
    }
    find[i] = founded;
  }

  for(int i = 0; i < M ; i++ ) {
    cout << find[i] << '\n'; //endl은 굉장히 느린 함수다 절대 사용 금지
  }
}
