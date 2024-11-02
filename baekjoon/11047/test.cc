#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int target_sum;
  cin >> N >> target_sum;

  vector<int> coins(N);

  for (int i = 0 ; i < N ; i++ ) {
    cin >> coins[i];
  }
  int cnt = N-1;
  int res = 0;
  while( target_sum  != 0 || cnt >= 0) {
    int num = target_sum / coins[cnt];
    if(num != 0) {
      res += num;
      target_sum = target_sum % coins[cnt];
    }

    cnt--;
  }

  cout << res << '\n';
}
