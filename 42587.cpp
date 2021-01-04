#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for (int i = 0 ; i < priorities.size() ; i++) {
        int priority = priorities[i];
        pq.push(priority);
        q.push(make_pair(priority, i));
    }
    
    while (true) {
        int pd = pq.top();
        int d = q.front().first;
        int loc = q.front().second;
        
        if (pd == d) {
            q.pop();
            pq.pop();
            answer++;
            
            if (loc == location) return answer;
        } else {
            q.pop();
            q.push(make_pair(d, loc));
        }
    }
}