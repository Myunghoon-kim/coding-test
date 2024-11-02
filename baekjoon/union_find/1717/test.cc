#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& index, int a) {
  if (index[a] == a)
    return a;
  else {
    index[a] = find(index, index[a]);
    return index[a];
  }
}

void _union(vector<int>& index, int a, int b) {
  a = find(index, a);
  b = find(index, b);

  if( a != b)
    index[b] = a;
}

bool check_same(vector<int>& index, int a, int b) {
  a = find(index, a);
  b = find(index, b);

  return a == b;
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int N , M;

  cin >> N >> M;

  vector<int> index(N+1);
  vector<int> node(2);
  // 초기화 index 초기화
  for(int i = 1; i < N + 1 ; i++)
    index[i] = i;

  for(int i = 0 ; i <  M ; i++) {
    cin >> node[0] >> node[1] >> node[2];
    if(node[0] == 0) {
      if (node[1] > node[2]) {
        _union(index, node[2], node[1]);
      } else {
        _union(index, node[1], node[2]);
      }
    } else {
      if (check_same(index, node[1], node[2]))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }

}
