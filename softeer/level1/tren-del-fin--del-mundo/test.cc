#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  pair<int,int> p[N];

  int cur_max ,pre_max= 0;
  int mark = 0;
  for (int i = 0 ; i < N ; i++) {
    int x,y;
    cin >> x >> y;
    p[i] = make_pair(x ,y);
  }
  for (int i = 0 ; i < N - 1 ; i++) {
    int x = p[i].first - p[i+1].first;
    int y = p[i].second - p[i+1].second;
    pre_max = max(pre_max, (int)(pow(x,2)+ pow(y,2)));
    if(pre_max > cur_max) {
      mark = i+1;
      cur_max = pre_max;
    }
  }

  cout << p[mark].first << " " << p[mark].second;
}
