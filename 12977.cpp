#include <vector>

using namespace std;

int N = 0;
int answer = 0;

bool isPrime(int n) {
    if (n == 1) return false;
    
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

void fn(const vector<int> &nums, int pos, int n, int cnt) {
    if (cnt == 3 && isPrime(n)) answer++;
    if (cnt == 3 || pos >= N) return;
    
    fn(nums, pos + 1, n + nums[pos], cnt + 1);
    fn(nums, pos + 1, n, cnt);
    
}

int solution(vector<int> nums) {
    N = nums.size();
    
    fn(nums, 0, 0, 0);
    
    return answer;
}