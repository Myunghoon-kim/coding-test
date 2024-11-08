#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long solution(int n, vector<vector<int>>& battery) {
  vector<long long> dp(n + 1, LLONG_MAX); // long long을 사용하여 초기화
  dp[0] = 0; // 0개 구매 시 비용 0

  for (const auto& b : battery) {
    int unit = b[0]; // 판매 단위
    long long price = b[1]; // 단위 가격

    // 판매 단위의 배수를 직접적으로 계산하여 DP 업데이트
    for (int i = unit; i <= n; i += unit) { // i를 판매 단위의 배수로 증가
      dp[i] = min(dp[i], dp[i - unit] + price);
    }
  }

  // 원하는 개수를 구매할 수 없는 경우 처리
  if (dp[n] == LLONG_MAX) {
    return -1; // 또는 무한대 대신 -1로 표시
  }

  return dp[n];
}

int main() {
  // 테스트 예제
  int n= 20;
  cin >> n;
  vector<vector<int>> battery = {{6, 30000}, {3, 18000}, {4, 28000}, {1, 9500}};
  cout << solution(n, battery) << endl;
  return 0;
}

