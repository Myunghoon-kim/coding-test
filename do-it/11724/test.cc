#include <iostream>
#include <vector>

using namespace std;

int N , M;
vector<vector<int>> nodes;
vector<bool> visited;

void dfs(int i) {
  if(visited[i])
    return;

  visited[i] = true;

  for(int node : nodes[i]) {
    if(!visited[node])
      dfs(node);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  nodes.resize(N + 1);
  visited.resize(N + 1, false);

  for(int i = 1 ; i <= M ; i++) {
    int e1, e2;
    cin >> e1 >> e2;
    nodes[e1].push_back(e2);
    nodes[e2].push_back(e1);
  }
  int cnt = 0;

  for(int i = 1; i <= N ; i++) {
    if(!visited[i]){
      cnt++;
      dfs(i);
    }
  }
  cout << cnt << endl;
}
