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
  for (int i = 0 ; i < N ; i++) {
    int x = p[i].first + p[i].second;
    cout << "Case #"<< i + 1<< ": " << x << endl;
  }

}
