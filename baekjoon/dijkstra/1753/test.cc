#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int,int> edge;
static int V, E, START;
static vector<int> m_distance;
static vector<bool> visited;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> V >> E >> START;
  m_distance.resize(V + 1);
  std::fill(m_distance.begin(), m_distance.end(), INT_MAX);
  visited.resize(V + 1);
  std::fill(visited.begin(), visited.end(), false);
  mlist.resize(V + 1);

  // 인접리스트 가중치 적용 진행
  for(int i = 0 ; i < E; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    mlist[a].push_back(make_pair(b, w));
  }

  //다익스트라 알고리즘 수행
  q.push(make_pair(0,START));
  m_distance[START] = 0;

  while(!q.empty()) {
    edge cur = q.top();
    q.pop();

    int cur_v = cur.second;

    if(visited[cur_v])
      continue;

    visited[cur_v] = true;
    for(int i = 0 ; i < mlist[cur_v].size(); i++) {
      edge tmp = mlist[cur_v][i];
      int next= tmp.first;
      int weight = tmp.second;

      if(m_distance[next] > m_distance[cur_v] + weight) {
        m_distance[next] = m_distance[cur_v] + weight;
        q.push(make_pair(m_distance[next],next));
      }
    }
  }

  for(int i = 1 ; i <= V; i++) {
    if(visited[i])
      cout << m_distance[i] << '\n';
    else
      cout << "INF\n";
  }
}
