// 에라토스테네스의 체 사용
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<bool> isPrime(n + 1);
    
    for (int i = 2 ; i <= n ; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2 ; i * i <= n ; i++) {
        if (!isPrime[i]) continue;
        
        for (int j = i * i ; j <= n ; j += i) {
            isPrime[j] = false;
        }
    }
    
    int answer = 0;
    
    for (int i = 2 ; i <= n ; i++) {
        if (isPrime[i]) answer++;
    }
    
    return answer;
}