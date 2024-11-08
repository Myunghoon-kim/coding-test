#include<vector>
#include<bits/stdc++.h>
using namespace std;

int dy[] = {-1,0,1,0}; // 상, 우, 하, 좌 이동을 위한 y 좌표 변화량
int dx[] = {0,1,0,-1}; // 상, 우, 하, 좌 이동을 위한 x 좌표 변화량

// BFS 함수는 주어진 맵에서 최단 경로를 찾습니다.
int BFS(vector<vector<int>> &maps){
	queue<pair<int,int>> q; // 탐색을 위한 큐

	int n = maps.size(); // 맵의 행 크기
	int m = maps[0].size(); // 맵의 열 크기

	vector<vector<int>> table(n,vector<int>(m,0)); // 방문한 위치와 거리를 기록하는 테이블

	q.push({0,0}); // 시작 위치 큐에 삽입
	table[0][0] = 1; // 시작 위치 거리를 1로 초기화

	while(q.size()){
		pair<int,int> current = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){ // 상, 우, 하, 좌 방향으로 탐색
			int ny = current.first + dy[i];
			int nx = current.second + dx[i];
			// 맵 범위를 벗어나거나, 벽을 만나거나, 이미 방문한 위치는 무시
			if(ny < 0 || nx < 0 || ny >= n || nx >= m || maps[ny][nx] == 0 || table[ny][nx]) 
				continue;
			table[ny][nx] = table[current.first][current.second] + 1; // 거리 업데이트
			q.push({ny,nx}); // 새 위치를 큐에 삽입
		}            
	}
	// 목표 지점에 도달한 경우 거리 반환, 그렇지 않으면 -1 반환
	return table[n - 1][m - 1] > 0 ? table[n - 1][m - 1] : -1;
}

// solution 함수는 주어진 게임 맵에서 BFS 함수를 호출하여 결과를 반환합니다.
int solution(vector<vector<int> > maps)
{
	int answer = BFS(maps);
	return answer;
}
