#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a , pair<int,int> b) {
  return a.second > b.second;
}

int main() {
  int W,N;
  int res = 0;
  cin >> W;
  cin >> N;

  vector<pair<int,int>> bags;
  for (int i = 0 ; i < N ; i++) {
    int m,p;
    cin >> m >> p;
    bags.push_back(make_pair(m,p));
  }
  sort(bags.begin(), bags.end(), cmp);
  for(int i = 0 ; i < N ; i++) {
    if(W - bags[i].first < 0){
      res = res + bags[i].second * W;
      break;
    }
    res = res + bags[i].second * bags[i].first;
    W -= bags[i].first;
  }
  cout << res << endl;
  return 0;
}
