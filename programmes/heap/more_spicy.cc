#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

unsigned int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),
                                                      scoville.end());

    while (pq.top() < K) {
        if(pq.size()==1)
            return answer = -1;
        int i = pq.top();
        pq.pop();
        pq.push(i + (pq.top() * 2));
        pq.pop();
        answer++;
    }

    return answer;
}
