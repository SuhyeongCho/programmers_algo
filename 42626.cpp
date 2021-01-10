#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0 ; i < scoville.size() ; i++) {
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()) {
        if (pq.top() >= K) break;
        
        if (pq.size() < 2) return -1;
        
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        
        pq.push(f + s * 2);
        
        answer++;
    }
    return answer;
}