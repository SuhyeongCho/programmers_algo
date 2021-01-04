#include <vector>
#include <queue>
#include <cmath>

#define INF 1987654321

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0 ; i < progresses.size() ; i++) {
        int d = ceil((100 - progresses[i])/(double)speeds[i]);
        q.push(d);
    }
    q.push(INF);
    
    for (int i = 1 ; i <= 100 ; i++) {
        int count = 0;
        while(true) {
            int d = q.front();
            if (i < d) {
                if (count != 0) answer.push_back(count);
                break;
            }
            q.pop();
            count++;
        }
    }
    
    return answer;
}