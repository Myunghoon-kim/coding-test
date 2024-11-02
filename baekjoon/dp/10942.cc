#include <iostream>
#include <vector>

using namespace std;

#define MAX 2001
vector<int> V;
int ANSWER[MAX][MAX] = {0,};// 0 은 불가 1는 가능;
int N, M;

int dp(vector<int>& v, int s, int e) {
  // index가 같으면
  if(s == e)
    return ANSWER[s][e] = 1;
  // 이미 값이 나와있다면
  if(ANSWER[s][e] == 1)
    return 1;
  //펜린드롭이 아니라면??
  if(v[s] != v[e]) {
    return ANSWER[s][e] = 0;
  } else {
    if(s + 1 <= e - 1) {
      //내부의 펜린드롭 확인 필요
      return ANSWER[s][e] = dp(v, s + 1, e - 1);
    } else {
      ANSWER[s][e] = 1;
      return 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  V.resize(N+1, 0);

  for(int i = 1 ; i <= N ; i++)
    cin >> V[i];

  cin >> M;

  for(int i = 0 ; i < M ; i++) {
    int s, e;
    cin >> s >> e;

    if (dp(V,s,e))
      cout << "1\n";
    else
      cout << "0\n";
  }

}
