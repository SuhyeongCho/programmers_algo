#include <vector>

using namespace std;

int fn(const vector<int> &numbers, const int &target, int value, int depth) {
    if (depth == numbers.size()) {
        if (target == value) return 1;
        else return 0;
    }
    
    int ans1 = fn(numbers, target, value + numbers[depth], depth + 1);
    int ans2 = fn(numbers, target, value - numbers[depth], depth + 1);

    return ans1 + ans2;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = fn(numbers, target, 0, 0);
    
    return answer;
}