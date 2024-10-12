#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int nNum, quizNum;
  vector<int> sum_index(100000,0);
  cin >> nNum >> quizNum;
  vector<int> answers;
  for(int i = 1 ; i <= nNum ; i++) {
    int tmp;
    cin >> tmp;
    sum_index[i] = sum_index[i-1] + tmp;

    //cout << "sum index " << i << "  " << sum_index[i] << endl;
  }

  for(int i = 0 ; i < quizNum ; i++) {
    int x, y;

    cin >> x >> y;

    //cout << sum_index[y]  << endl;
    //cout << sum_index[x-1]  << endl;
    answers.push_back(sum_index[y] - sum_index[x - 1]);
  }
  for(int i : answers) {
    cout << i << endl;
  }
}
