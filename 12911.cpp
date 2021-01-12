#include <string>
#include <vector>

using namespace std;

int getNumOfOne(int n) {
    int cnt = 0;
    while (n) {
        if (n % 2) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = getNumOfOne(n);
    while (n++) {
       if (cnt == getNumOfOne(n)) {
           return n;
       }
    }
    return answer;
}