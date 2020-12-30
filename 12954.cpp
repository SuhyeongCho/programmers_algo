#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0, y = x ; i < n ; i++, y += x) {
        answer.push_back(y);
    }
    return answer;
}