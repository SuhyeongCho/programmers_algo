#include <algorithm>

using namespace std;

int answer = 0;

void fn(int n, int m, int a, int b, int cnt) {
    if (n >= m) return;
    
    int mid = (n + m) / 2;
    if (a <= mid &&  b > mid) answer -= cnt;
    else if (b <= mid) fn(n, mid, a, b, cnt + 1);
    else fn (mid + 1, m, a, b, cnt + 1);
}



int solution(int n, int a, int b) {
    int t = n;
    while (t) {
        answer++;
        t /= 2;
    }
    
    if (a > b) swap(a, b);
    fn(1, n, a, b, 1);
    
    return answer;
}