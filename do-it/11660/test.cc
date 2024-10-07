#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N = 0, M = 0;
  cin >> N >> M;

  //int index[N+1][N+1] = {0};
  //int sum[N+1][N+1] = {0};
  vector< vector<int> > index(N + 1, vector<int>(N + 1 , 0));
  vector< vector<int> > sum(N + 1, vector<int>(N + 1 , 0));


  vector<int> res(M);

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      int tmp;
      cin >> tmp;
      index[i][j] = tmp;
      sum[i][j] = sum[i-1][j] + sum[i][j-1]  - sum[i-1][j-1] + index[i][j];
    }
  }
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      cout << sum[i][j] << " " ;
    }
    cout << endl;
  }
  for(int i = 0 ; i < M; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    res[i] = sum[x2][y2] - sum[x1-1][y2] - sum [x2][y1-1] + sum[x1-1][y1-1];
  }
  for(int i = 0 ; i < M ; i++) {
    cout << res[i] << endl;
  }
}


