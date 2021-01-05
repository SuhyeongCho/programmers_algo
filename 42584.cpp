#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N, -1);
    
    vector<int> v;
    
    for (int i = 0 ; i < N ; i++) {
        while (!v.empty() && prices[v.back()] > prices[i]) {
            answer[v.back()] = i - v.back();
            v.pop_back();
        }
        v.push_back(i);
    }
    
    while(!v.empty()) {
        answer[v.back()] = N - v.back() - 1;
        v.pop_back();
    }
    
    return answer;
}