#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> stones;

  for(int i = 1 ; i <= N; i++) {
    int tmp;
    cin >> tmp;
    stones.push_back(tmp);
  }

  int pre_max = 0, cur = 1;

  for(int i = 1; i <= N ; i++) {
    if(stones[i] >= stones[i-1]) {
      cur++;
    } else {
      pre_max = max(pre_max, cur);
      cur= 1;
    }
  }
  pre_max = max(pre_max, cur);
  cout << pre_max << endl;
}
