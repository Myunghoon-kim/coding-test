#include <iostrea>
#include <queue>
#include <vector>
typedef pair<int, int> Node;
static int M, N, K;
static int W[1001][1001];
static priority_queue<int> distQueue[1001];
int main () {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M >> K;

  for(int i = 0 ; i < M ; i++ ) {
    int a, b, c;
    cin >> a >> b >> c;
    W[a][b] = c;
  }
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push(make_pair(0,1));
  distQueue[1].push(0);
}
