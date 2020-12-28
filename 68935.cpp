#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int> v;
    
    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }
    
    int siz = v.size();
    int answer = 0;
    for (int i = 0 ; i < siz ; i++) {
        answer += (v[siz - i - 1] * pow(3, i));
    }
    return answer;
}