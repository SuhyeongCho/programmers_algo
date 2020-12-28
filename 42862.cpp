#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<bool> lostMap(n, false), reserveMap(n, false);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int lostIndex = 0, reserveIndex = 0;
    for (int i = 0 ; i < n ; i++) {
        if (lostIndex < lost.size() && i == lost[lostIndex] - 1) {
            lostMap[i] = true;
            lostIndex++;
        }
        if (reserveIndex < reserve.size() && i == reserve[reserveIndex] - 1) {
            reserveMap[i] = true;
            reserveIndex++;
        }
        
        if (lostMap[i] && reserveMap[i]) {
            lostMap[i] = false;
            reserveMap[i] = false;
        }
    }
    
    for (int i = 0 ; i < n ; i++) {
        if (!lostMap[i]) continue;
        if (i > 0 && reserveMap[i - 1]) {
            reserveMap[i - 1] = false;
            lostMap[i] = false;
            continue;
        }
        if (i < n - 1 && reserveMap[i + 1]) {
            reserveMap[i + 1] = false;
            lostMap[i] = false;
            continue;
        }
    }
    
    for (int i = 0 ; i < n ; i++) {
        if (lostMap[i]) answer--;
    }
    
    return answer;
}