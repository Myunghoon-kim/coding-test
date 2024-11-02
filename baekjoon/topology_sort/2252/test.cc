#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  vector<int> D( N + 1);
  vector<vector<int>> index(N+1);

  for(int i = 0 ; i < M ; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    index[node1].push_back(node2);
    D[node2]++;
  }
  queue<int> queue;

  for(int i = 1 ; i <= N ; i++) {
    if( D[i] == 0)
      queue.push(i);
  }

  while(!queue.empty()){
    int front = queue.front();
    queue.pop();

    cout << front << " ";
    for(int i : index[front]) {
      D[i]--;
      if(D[i] == 0)
        queue.push(i);
    }
  }

}
