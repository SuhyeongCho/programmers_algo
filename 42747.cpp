#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int len = citations.size();
    
    int last = citations.back();
    
    for (int i = 0 ; i < last ; i++) {
        int h = i;
        int t = 0, f = 0;
        for (int j = 0 ; j < len ; j++) {
            if (citations[j] >= h) t++;
            else f++;
        }
        if (t >= h && f <= h) answer = h;
    }
    return answer;
}