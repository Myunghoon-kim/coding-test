#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int start_index = 1, end_index = 1;
  int sum = 0, res = 0;
  cin >> N;

  for(; start_index <= N ; start_index++) {
    for( end_index = start_index; end_index <= N ; end_index++) {
      sum += end_index;
      if(sum == N) {
        sum = 0;
        res++;
        break;
      } else if(sum > N) {
        sum = 0;
        break;
      }
    }
  }
  cout << res << endl;
}
