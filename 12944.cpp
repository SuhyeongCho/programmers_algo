#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int n = arr.size();
    for (int i = 0 ; i < n ; i++) {
        answer += arr[i];
    }
    answer /= n;
    return answer;
}